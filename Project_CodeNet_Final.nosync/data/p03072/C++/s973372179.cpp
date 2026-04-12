#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define cool ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int  long long int
#define pb push_back
#define fe first
#define se second
#define endl "\n"
#define pii pair<int, int>
#define vi vector<int> 
#define vvi vector<vi>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define ALL(c) (c).begin(),()c.end() 

#define PI 3.14159265358979323846
const int N = 3e5 + 10;
const int INF=2e9;

int MOD=1e9+7;

void solve() {
    int n,tot=0;
    cin>>n;
    vi v(n);
    
    for(int i=0;i<n;i++)
        cin>>v[i];
        
    for(int i=0;i<n;i++) {
		   int cnt=0;
		    for(int j=0;j<i;j++) {
				   if(v[j]>v[i]){
				      cnt++;
				      break;
				   }
				}
				if(cnt==0)
				   tot++;		    
		}
		
		
		cout<<tot<<endl;  
        
	
	}  

int32_t main() {
  cool;
  int t = 1;
  while (t--)
	solve();

  return 0;
}
