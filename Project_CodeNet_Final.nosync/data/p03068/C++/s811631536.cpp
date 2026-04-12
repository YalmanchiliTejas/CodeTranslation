#include <bits/stdc++.h>
typedef long long ll;
#define REP(i,a) for(int i = 0; i < (a); i++)
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	REP(i,s.length()){
		if(s[i] != s[k - 1])s[i] = '*';
	}
	cout << s << endl;
}