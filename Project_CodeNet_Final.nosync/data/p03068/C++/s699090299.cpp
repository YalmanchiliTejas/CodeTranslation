#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, k;
	string s;
	cin >> n >> s >> k;
	rep(i, n){
		if(s.at(i) == s.at(k-1)) cout << s.at(k-1);
		else cout << '*';
	}
	cout << endl;
	return 0;
}