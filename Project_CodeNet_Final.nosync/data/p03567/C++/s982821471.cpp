#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;cin >> s;
	rep(i,s.size()-1){
		if(s.substr(i,2)=="AC"){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}