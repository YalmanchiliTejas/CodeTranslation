#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define ll long long
#define fill fill_n
#define pf push_front
#define pb push_back
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define comp(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define infile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<pair<int,int>> vpi;

const int M = 1e9+7;
const int N = 2e5;
ll po(int,int);


void solve(){
    int n;cin>>n;
    
    ll a;
    
    ll s=0,ans=0;
    
    FOR(i,0,n){
        cin>>a;
        ans = (ans + (a*s)%M)%M;
        s = (s+a)%M; 
    }
    cout<<ans<<"\n";
    
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t=1;
    //cin>>t;
    FOR(i,1,t+1){
        //cout<<"Case #"<<i<<": "; 
        solve();
    }
    
	return 0;
	
	
}


ll po(int a,int b){
    if(b==0) return 1;
    ll ans=1;
    if(b%2==0){
        ans = po(a,b/2)%M;
        ans=(ans%M * ans%M)%M;
    }
    else{
        ans = po(a,(b-1)/2)%M;
        ans = (ans%M * ans%M * a)%M;
    }
    return ans%M;
}
