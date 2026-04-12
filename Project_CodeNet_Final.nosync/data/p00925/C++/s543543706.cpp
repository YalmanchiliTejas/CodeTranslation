#include <bits/stdc++.h>

using namespace std;

int in = 0;

int num(string str) {
    int res = str[in] - '0';
    in++;
    return res;
}

int mul(string str) {
    int res = num(str);
    int len = str.length();
    while (in < len && str[in] == '*') {
        in++;
        int temp = num(str);
        res *= temp;
    }
    return res;
}

int eval(string str) {
    int res = mul(str);
	int len = str.length();
    while (in < len) {
    	in++;
        res += mul(str);
    }
    return res;
}
    
int ltor(string str) {
    int res = str[0] - '0';
	int len = str.length();
    for (int i = 1; i < len; i += 2) {
        if (str[i] == '+') {
            res += str[i + 1] - '0';
        }
		else {
            res *= str[i + 1] - '0';
        }
   }     
   return res;
}

int main() {
    string expr;
	cin >> expr;
    int result;
	cin >> result;
    int m = eval(expr);
    int l = ltor(expr);
    if(result == m && result == l){
		cout << "U\n";
    }
	else if (result == m) {
       cout << "M\n";
    }
	else if (result == l) {
       cout << "L\n";
    }
	else {
       cout << "I\n";
    }
	return 0;
}

