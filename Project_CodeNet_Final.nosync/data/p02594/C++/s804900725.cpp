#include<bits/stdc++.h> 
using namespace std; 
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define lcm(a,b)     (a*b)/__gcd(a,b)
#define bs(v,x)      binary_search(v.begin(),v.end(),x)
#define ub(v,x)      upper_bound(v.begin(),v.end(),x)
#define lb(v,x)      lower_bound(v.begin(),v.end(),x)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(a) (a).begin(),(a).end() 
#define inp(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define trace(v) for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cerr<<endl;
#define printv(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout<<"\n";
#define Pi 3.14159265
#define PII pair<ll, ll>; 
#define reset(x) memset(x,'z',sizeof(x))
#define f first
#define s second
#define mp make_pair
#define pq1 priority_queue<ll>;
#define pq2 priority_queue<ll, vector<ll>,greater<ll>>;
typedef long long ll;
typedef vector<ll> vll;
typedef bool B;
typedef double ff;
//const ll INF=1e10;
const ll MAX_N = 100005;
char en='\n';   
         
         void solve()
         {
            ll x;
            cin>>x;
            if(x>=30)
               cout<<"Yes";
            else cout<<"No";
         }

         int main()
         { 
               ios_base::sync_with_stdio(false);cin.tie(NULL); 
               #ifndef ONLINE_JUDGE 
                        freopen("input.txt", "r", stdin); 
                        freopen("error.txt", "w", stderr); 
                        freopen("output.txt", "w", stdout); 
               #endif 
                        int t=1; 
                        //cin>>t; 
                        while(t--) 
                        {   
                           solve();
                           cout<<en;
                        } 
               cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
               return 0; 
         }