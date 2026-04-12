#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) FOR(i,0,b)
#define INF 1e18
#define dump(x) cerr<<#x<<"="<<x<<endl
#define all(a) (a).begin(),(a).end()
typedef pair<int,int> P;
template <class T> void chmin(T & a, T const & b) { if (b < a) a = b; }
template <class T> void chmax(T & a, T const & b) { if (b > a) a = b; }
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
using ll = long long;
const ll mod = LLONG_MAX;


int h,ma,ans;
int a[110];
int main(){
    cin>>h;
    rep(i,h){
        if(i>0)ma=max(ma,a[i-1]);
        cin>>a[i];
        
        if(a[i]>=ma)ans++;
    }
    cout<<ans<<endl;
}
