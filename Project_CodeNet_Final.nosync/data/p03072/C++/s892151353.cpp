#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reprep(i,j,w,h) rep(j,h)rep(i,w)
#define rrep(i,m, n) for(int i = m; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<int>(n,a)));
typedef long long ll;
const int INF = 2000000000;
const long INF64 = 1000000000000000ll;
const ll MOD = 1000000007LL;
int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    rep(i,n)std::cin >> a[i];
    int ans=0;
    rep(i,n){
        bool han=1;
        rep(j,i){
            if(a[j]>a[i])han=0;
        }
        if(han)ans++;
    }
    std::cout << ans << std::endl;
}