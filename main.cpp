#include "notation.h"

using namespace std;

int main() {
	string prompt = "Enter infix expression:";
	string infix_exp = input(&prompt);
	cout << "prefix:" << to_prefix(infix_exp) << endl;
	cout << "postfix: " << to_postfix(infix_exp) << endl;
	cout << "executed in " << (double)clock()/CLOCKS_PER_SEC << "s" << endl;

	return 0;
}

