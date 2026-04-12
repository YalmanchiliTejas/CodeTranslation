//Abhinav ---IIIT_A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>>
#define vi vector<int>
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
#define my vector<pii>
ld pie=3.141592653589;
int mod=1e9+7;


bool Compare(pii a, pii b)
{
	return a.ff > b.ff;
}
priority_queue<pii, vector<pii>, function<bool(pii, pii)>> pq(Compare);

void solve(){
	int n; cin>>n;
	int a[n]; f(i,0,n) cin>>a[i];
	int sum=a[n-1];
	int ret=0;
	for(int i=n-2;i>=0;--i){
		ret+=a[i]*sum;
		ret%=mod;
		sum+=a[i]; sum%=mod;
	}
	cout<<ret;
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t=1; //cin>>t;
  while(t--) solve();
  return 0;
}
// check for overflows dummy !!!