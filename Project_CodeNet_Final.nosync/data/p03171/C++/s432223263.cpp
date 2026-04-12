#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.14159265359
#define all(v) v.begin(),v.end()
#define vil vector<long int>
#define vi vector<int> 
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define ub upper_bound
#define lb lower_bound
#define INF 1000000007 
#define MOD 998244353
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fill(s,x,n) vector<s> x(n); rep(i,0,n) cin>>x[i];
#define sec second
#define fir first
#define acc(v) accumulate(v.begin(),v.end(),0)
bool mysort(const pair<int,int> &a,  
               const pair<int,int> &b){
                   if(a.first==b.first){
                       return a.sec<b.sec;
                   }
                   return a.first<b.first;
    
}
 
ll power(ll a, ll b){
	ll res=1;
	while(b--){
		res*=a;
	}
	return res;
}
void solve(){
int n;
cin>>n;
fill(ll,a,n);
ll dp[n][n];
for(int l=n-1;l>=0;l--){
    for(int r=l;r<n;r++){
        if(l==r){
            dp[l][r]=a[l];
        }
        else{
        dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
    }
}
}
cout<<dp[0][n-1]<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
ll T;
T=1;
//cin>>T;
while(T--){
solve();
}
return 0;
}