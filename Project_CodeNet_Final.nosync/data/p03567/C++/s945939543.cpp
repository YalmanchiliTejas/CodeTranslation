#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int f = 0;
	rep(i, s.size()-1){
		if(s.at(i) == 'A' && s.at(i+1) == 'C') f = 1;
	}
	if(f == 1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}