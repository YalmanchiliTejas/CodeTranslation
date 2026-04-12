#include <bits/stdc++.h>
using namespace std;

string s;
int n, l;
long long a, b;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> s >> n;
	l = s.size();
	if(l == 1){
		if(s[0] - '0' == n) cout << "U\n";
		else cout << "I\n";
		return 0;
	}
	a = s[0] - '0';
	for(int i=2; i<l; i+=2){
		if(s[i-1] == '+') a += s[i] - '0';
		else a *= s[i] - '0';
	}
	for(int i=0; i<l; i+=2){
		long long t = s[i] - '0';
		while(i+2 < l && s[i+1] == '*'){
			t *= s[i+2] - '0';
			i += 2;
		}
		b += t;
	}
	if(n == a){
		if(n == b) cout << "U\n";
		else cout << "L\n";
	}else{
		if(n == b) cout << "M\n";
		else cout << "I\n";
	}
//	cout << a << " " << b << "\n";
}
