#include <iostream>
#include <ctime> // clock for measuring efficiency
#include <string>
#include <vector>

using namespace std;

string input(string *message) {
	cout << *message << endl;
	string user_input;
	getline(cin, user_input);

	return user_input;
}

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
	// return stack[stack.length() - 1];
	return stack.back();
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
	}
	while (sym_stack.length() > 0) {
		new_exp += stack_top(sym_stack);
		sym_stack.erase(sym_stack.length() - 1, 1);
	}

	return new_exp;
}

string to_prefix(string str) {
	return reverse(to_postfix(swap(reverse(str), '(', ')')));
}
