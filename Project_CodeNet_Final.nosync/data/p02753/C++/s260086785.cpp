#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
#define endl '\n'
#define loop(i, m, n) for (lli i = m; i < n; i++)
#define loope(i, m, n) for (lli i = m; i <= n; i++)
#define epool(i, m, n) for (lli i = m; i >= n; i--)
#define pool(i,m,n) for(lli i=m; i>n; i++)
#define maxe *max_element
#define mine *min_element
#define plli pair<lli, lli>
#define mod 1000000007
#define mod2 998244353
#define vt vector<lli>
#define fi first
#define se second
#define pb push_back
#define umap unordered_map
#define mmap multimap
#define mp make_pair
#define inp1(a) cin >> a
#define inp2(a, b) cin >> a >> b
#define inp3(a, b, c) cin >> a >> b >> c
#define inp4(a, b, c, d) cin >> a >> b >> c >> d
#define inp5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define inp6(a, b, c, d, e, f) cin >> a >> b >> c >> d >> e >> f
#define pr0() cout << " "
#define pr1(a) cout << a << " "
#define pr2(a, b) cout << a << " " << b << " "
#define pr3(a, b, c) cout << a << " " << b << " " << c << " "
#define pr4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << " "
#define emp emplace //used to push a pair etc..
#define empf emplace_front
#define empb emplace_back
#define ret(x) return cout << x, 0;
#define all(v) v.begin(),v.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//especially for deque both sides dynamic
#define pf push_front
//list doubly linked lists can insert at mid. splice fn can be used
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
 
lli gcd(lli a, lli b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
lli lcm(lli a, lli b){
    return (a * b) / gcd(a, b);
}
 
lli modi(lli n,lli m=mod){ 
    if(n==0) return 0;
    n%=m;
    n+=m;
    n%=m;
    return n;
}
 
lli mpow(lli base, lli exp){
    base %= mod;
    lli result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((lli)result * base) % mod;
        base = ((lli)base * base) % mod;
        exp >>= 1;
    }
    return result;
}
const lli INF=1e18;
const lli N=2e5+5;
lli a[N]={0},b[N]={0};

int32_t main(){
    fast_io
    lli i = 0,j=0;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    
    vt v,v1,v2;
    lli a,b,c,d,e,f,n,k;

    string s;
    cin >> s;

    if(s=="AAA" || s=="BBB") cout << "No";
    else cout << "Yes";


}