#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int n;
	while(cin>>n && n!=0){
		vi d(n);
		rep(i,0,n) cin>>d[i];

		bool f[100000];
		memset(f,0,sizeof(f));

		rep(i,0,n){
			f[i]=d[i];
			if(i%2 && f[i-1]!=d[i]){
				repb(j,i-1,0){
					if(f[j]==d[i]) break;
					f[j]=d[i];
				}
			}
		}

		int ans=0;
		rep(i,0,n) if(!f[i]) ans++;
		o(ans);
	}
}