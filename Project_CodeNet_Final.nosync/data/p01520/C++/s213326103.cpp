#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int n,t,e;
	cin>>n>>t>>e;
	vi x(n);
	rep(i,0,n) cin>>x[i];
	int ans=-1;
	rep(i,0,n){
		for(int j=1;;j++){
			if(t-e<=j*x[i] && j*x[i]<=t+e){
				ans=i+1;
				i=n;
				break;
			}
			if(j*x[i]>t+e) break;
		}
	}
	cout<<ans<<endl;
}