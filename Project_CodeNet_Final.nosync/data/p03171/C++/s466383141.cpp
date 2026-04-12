#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll n,arr[3005];
ll dp[3005][3005];
bool pres[3005][3005];
ll answer(ll l,ll r){
	if(r<l) return 0;
	if(pres[l][r]) return dp[l][r];
	int turn = (n - (r-l+1))%2;
	ll ans;
	if(turn==0){
		//taro
		ans=max(arr[l]+answer(l+1,r),arr[r]+answer(l,r-1));
	}else{
		//jiro
		ans=min(-arr[l]+answer(l+1,r),-arr[r]+answer(l,r-1));
	}
	pres[l][r]=true;
	return dp[l][r]=ans;
}
void solve(ll caseno){
	ll i,j;
	cin>>n;
	fo(i,0,n) cin>>arr[i];
	mset(pres,0);
	ll ans=max(arr[n-1]+answer(0,n-2),arr[0]+answer(1,n-1));
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
