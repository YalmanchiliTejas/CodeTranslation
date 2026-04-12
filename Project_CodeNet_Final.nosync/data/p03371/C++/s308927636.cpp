#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

ll a,b,ab;
// a->     cost of 1A pizza
// b->     cost of 1B pizza
// ab->    cost of 1A+1B pizza(combined)

ll _find(ll x,ll y){
   
   // buying zero pizzas of size AB
   ll ans=a*x + b*y;
   for(int i=1;i<=max(x,y);i++){
       ll cost=i*ab;
       if(x>i){
           cost += (x-i)*a;
       }
       if(y>i){
           cost += (y-i)*b;
       }
       ans=min(ans,cost);
   }
   return ans;
}

void solve(){
    ll n,m;
    cin>>a>>b>>ab>>n>>m;
    ab*=2;
    
    cout<<_find(n,m);
}





int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}