#include <iostream>

using namespace std;

string s;
long long x;

int main(){
	cin >> s;
	cin >> x;
	long long t1 = 0, t2 = 0;
	int last_sign = 0;
	for (int i=0;i<s.length();i+=2){
		if (last_sign){
			if (t1*(s[i]-'0') <= x)
				t1 = t1*(s[i]-'0');
		}else t1 += s[i]-'0';
		if (i+1 != s.length() and s[i+1] == '+') last_sign = 0;
		else last_sign = 1;
	}
	long long current_multiple = 1;
	for (int i=0;i<s.length();i++){
		if (s[i] == '+'){
			t2 += current_multiple;
			current_multiple = 1;
		} else if (s[i] != '*'){
			if (s[i]=='0' or current_multiple <= x)
				current_multiple *= s[i]-'0';
		}
	}
	t2+=current_multiple;
	if (t1 == x and t2!=x){
		cout << "L";
	}
	else if (t1!=x and t2==x){
		cout << "M";
	}
	else if (t1 == x and t2 == x){
		cout << "U";
	}
	else cout << "I";
	cout << "\n";
}