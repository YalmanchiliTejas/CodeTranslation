#include <iostream>
#include <string>
#include <cstdlib>
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
using namespace std;
bool check(string s, int n) {
	if(n%15==0) {
		if(s=="FizzBuzz") return true;
		else return false;
	} else if(n%5==0) {
		if(s=="Buzz") return true;
		else return false;
	} else if(n%3==0) {
		if(s=="Fizz") return true;
		else return false;
	} else {
		if(atoi(s.c_str()) == n) return true;
		else return false;
	}
}
int main(){
	int m,n;
	string s;
	while(cin >> m >> n, (m || n)) {
		bool f[1010] = {};
		string s[10010];
		int cur = 0;
		rep(i,n) {
			cin >> s[i];
		}
		int p = m;
		rep(i,n) {
			if(!check(s[i], i+1)) {
				f[cur%m] = true;
				p--;
			}
			if(p<=1) break;
			while(f[++cur%m]) {}
		}
		bool b = 1;
		rep(i,m) {
			if(!b && !f[i]) {
				cout << " " << i+1;
			}
			if(b && !f[i]) {
				cout << i+1;
				b = 0;
			}
		}
		cout << endl;
	}
}