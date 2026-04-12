#include<bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define endl "\n"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
 
typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef pair<ll,pair<ll,ll> > ppp;
 
const ll N    = 5e5+5;
const ll INF  = 1e9;
const ll mod  = 1e9+7;


  
int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
  
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
  
        else if (v[i] >= tail[length - 1]) 
            tail[length++] = v[i];
        else{
            auto pos = upper_bound(tail.begin(),tail.begin()+length,v[i])-tail.begin();
            tail[pos] = v[i]; 
        }
    } 
  
    return length; 
} 

void solve()
{
    ll x,n,d;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
        cin>>x,v.push_back(x);
    
    reverse(all(v));
    cout<<LongestIncreasingSubsequenceLength(v)<<endl;
}     
 
int main(){
    FAST
    int t= 1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
} 