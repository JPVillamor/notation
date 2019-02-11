#include <iostream>
#include <vector>

using namespace std;
/* this stack class might be useful in the future.
class Stack {
private:
	char type;
	void *temp;
	vector<void*> data;
public:
	Stack(char t) { type = t; }
	void push_data(void *data_ptr); // add pointer to vector
	void pop_data(void *data_dst, void *data_ptr); // copy to dst
};

void Stack::push_data(void *data_ptr) {
	switch(type) {
	case 'c':
		data.push_back((char *)data_ptr);
		break;
	case 'i':
		data.push_back((int *)data_ptr);
		break;
	case 'l':
		data.push_back((long *)data_ptr);
		break;
	case 'f':
		data.push_back((float *)data_ptr);	
		break;
	case 'd':
		data.push_back((double *)data_ptr);
		break;
	case 's':
		data.push_back((string *)data_ptr);
		break;
	}
} */

string reverse(string str) {
	string new_str = "";

	for (int i = str.length() - 1; i >= 0; i--) {
		new_str += str[i];
	}

	return new_str;
}

string swap(string str, char a, char b) {
	string new_str = str;

	for (int i = 0; i < new_str.length(); i++) {
		if (new_str[i] == a) {
			new_str[i] = b;
		} else if (new_str[i] == b) {
			new_str[i] = a;
		}
	}

	return new_str;
}

char stack_top(string stack) {
	return stack[stack.length() - 1];
}

string to_postfix(string str) {
	string symbols = "(+*-/^>)", new_exp = "";
	string sym_stack = "";

	for (int i = 0; i < str.length(); i++) {
		if (symbols.find(str[i]) != -1) {
			sym_stack += str[i];
		} else {
			new_exp += str[i];
		}

		if (stack_top(sym_stack) == ')') {
			char temp;
			do {
				temp = stack_top(sym_stack);
				sym_stack.erase(sym_stack.length() - 1, 1);
				if (temp != ')' && temp != '(')
					new_exp += temp;
			} while (temp != '(');
		}
		/*
		cout << "exp: " << new_exp << endl;
		cout << "stk: " << sym_stack << endl;
		*/
	}
	/*
	cout << "exp: " << new_exp << endl;
	cout << "stk: " << sym_stack << endl;
	*/
	while (sym_stack.length() > 0) {
		new_exp += stack_top(sym_stack);
		sym_stack.erase(sym_stack.length() - 1, 1);
	}

	return new_exp;
}

int main() {
	string infix_exp = "((a+b)*(c-d))+e";
	cout << infix_exp << endl;
	string exp = swap(reverse(infix_exp), '(', ')');
	cout << exp << endl;
	cout << reverse(to_postfix(exp)) << endl;


	return 0;
}
