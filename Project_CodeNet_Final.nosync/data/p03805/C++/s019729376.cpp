#include<bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define acc_io cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define vvl vector<vector<ll>>
#define vl  vector<ll>
#define rep(i,sta,end) for(ll i=sta;i<end;i++)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
typedef long long ll;
#define pb push_back
const ll MOD = 1000000007;
const double PI = acos(-1);
//name[i]   -> vl  name(i)
//name[i][j]-> vvl name(i,vl(j))
//or-> ||
//int n,q;
//int ans;
//string s;

signed main(){
	acc_io;
	int n,m;
	cin>>n>>m;
	vvl p(n+1,vl());
	rep(i,0,m){
		int a,b;
		cin>>a>>b;
		p.at(a).pb(b);
		p.at(b).pb(a);
	}
	int a[n+1];
	int ok=0;
	int ans=0;
	rep(i,1,n+1) a[i]=i;
	do{
//		rep(i,1,n+1) cout<<a[i]<<" ";
//		cout<<endl;
		rep(i,1,n){
			ok=0;
			rep(j,0,p.at(a[i]).size()){
//				cout<<i<<":";
//				cout<<p.at(a[i]).at(j)<<":"<<a[i+1]<<endl;
				if( p.at(a[i]).at(j)==a[i+1] ){
//					cout<<i<<":OK"<<endl;
					ok=1;
					break;
				}
			}
			if(ok==0) break;
		}
		if(ok==1) ans++;
		ok=0;
	}while(next_permutation(a+2,a+n+1));
	cout<<ans<<endl;
	return 0;
}
