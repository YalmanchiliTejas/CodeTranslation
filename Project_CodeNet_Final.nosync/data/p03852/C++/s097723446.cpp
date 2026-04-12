#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	char c;cin >> c;
	string s="aiueo";
	rep(i,5) if(c==s.at(i)){
		cout << "vowel" << endl;
		return 0;
	}
	cout << "consonant" << endl;
}
