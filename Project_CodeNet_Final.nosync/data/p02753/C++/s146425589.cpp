#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e5+50;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("atcoder.txt", "r", stdin);
	int tc = 1;
	for(int T=1; T<=tc; T++){
		string s; cin>>s;
		if(s[0] == 'A' and s[1] == 'A' and s[2] == 'A'){
			cout<<"No\n";
		}
		else if(s[0] == 'B' and s[1] == 'B' and s[2] == 'B'){
			cout<<"No\n";
		}
		else cout<<"Yes\n";
	}
	return 0;
}