#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) ((a+b-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
const int MOD=1000000007;
//const int INF=LLONG_MAX/2;

signed main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n,count=0;
    cin>>n;
    Vi a(n);
    REP(i,0,n) cin>>a[i];
    
    multiset<int> ans;
    REP(i,0,n){
        auto it=ans.lower_bound(a[i]);
        if(it==ans.begin()){
            ans.insert(a[i]);
        }else{
            it--;
            ans.erase(it);
            ans.insert(a[i]);
        }
    }
    cout<<ans.size()+count<<endl;
    return 0;
}
