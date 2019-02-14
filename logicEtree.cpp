#include "notation.h"

using namespace std;

class Node {
private:
	char token;
	int data;
	int isNegated = 0; // bit field for data and negated?
	Node *left, *right;
public:
	Node(char c, int d, Node *l, Node *r);
	char getToken() { return token; }
	int getData() { return data; }
	int getNeg() { return isNegated; }
	Node *getLeft() { return left; }
	Node *getRight() { return right; }
	void setToken(char c) { token = c; }
	void setData(int d) { data = d; }
	void setNeg(int n) { isNegated = n; }
	void setLeft(Node *l) { left = l; }
	void setRight(Node *r) { right = r; }
};

Node::Node(char c, int d, Node *l, Node *r) {
	token = c;
	data = d;
	left = l;
	right = r;
}

class Extree {
private:
	Node *root;
	string symbols = "+-*/>";
	string expression;
	vector<int> values;
public:
	Extree() { root = NULL; }
	void setExp(string s) { expression = s; }
	void Print(Node *start); // check if built properly
	void Insert(Node *newNode, int &index);
	void Assign(Node *start, int &index);
	void Calculate(Node *start);
	void main(); // set root. input expression.
};

void Extree::Insert(Node *newNode, int &index) {
	// for '!' check then assign next symbol as token, setNeg=1
	// set left
	// if symbol, insert(left, exp, ++index)
	// index++. new node temp
	// set right.
	// if symbol, insert(right, exp, ++index)
	Node *temp = new Node(expression[++index], 999, NULL, NULL);
	newNode->setLeft(temp);
	
	if (temp->getToken() == '!') {
		temp->setToken(expression[++index]);
		temp->setNeg(1);
	}

	if (symbols.find(temp->getToken()) != -1) {
		Insert(temp, ++index);
	}
	
	temp = new Node(expression[++index], 999, NULL, NULL);
	newNode->setRight(temp);
	
	if (symbols.find(temp->getToken()) != -1) {
		Insert(temp, ++index);
	}
	
	if (temp->getToken() == '!') {
		temp->setToken(expression[++index]);
		temp->setNeg(1);
	}
}

void Extree::main() {
	int index = 0;
	setExp("+*+ab-cde");
	root->setToken() = expression[index];
	if (root->getToken() == '!') {
		root->setToken()
	}
}

int main() {
	Extree myTree;
	myTree.main();

	return 0;
}
