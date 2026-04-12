#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for(int i =0 ; i < n; ++i)
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair < int, int >
typedef vector<int> vi;
typedef  long long ll;
const int mod =1e9+7;
const int N = (int)2e5 + 5;

void solve(){
		int q;
		cin>>q;
		int cnt[26];
		rep(i,26)cnt[i]=1e9+7;
		while(q--){
			string s;
			cin>>s;
			int res[26];
			rep(i,26)res[i]=0;
			rep(i,sz(s)){
				res[s[i]-'a']++;
			}
			rep(i,26){
				cnt[i]=min(cnt[i],res[i]);
				//cout<<cnt[i]<<" "<<res[i]<<" ";
			}
			//cout<<"\n";
		}
		rep(i,26){
			if(cnt[i]>0){
				int x=cnt[i];
				while(x--){
					cout<<char(i+'a');
				}
			}
		}
}

int main(){
	Red;
	int t=1;
	// cin>>t;
	while(t--)
	solve();
	return 0;
}