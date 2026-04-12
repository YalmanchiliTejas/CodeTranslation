#include<bits/stdc++.h>
using namespace std;
const int maxn =  1e6 + 10;
#define ll long long
#define ios std::ios::sync_with_stdio(false)
const ll INF(0x3f3f3f3f3f3f3f3fll);
const int inf(0x3f3f3f3f);
#define int long long
#define pb(a) push_back(a)
#define debug(a) cout << "a : " << a << '\n'
#define mp(a , b) make_pair(a ,b)
const int mod = 1e9 + 7;
const double eps = 1e-6;
template<typename T>void read(T &res){bool flag=false;char ch;while(!isdigit(ch=getchar()))(ch=='-')&&(flag=true);
for(res=ch-48;isdigit(ch=getchar());res=(res<<1)+(res<<3)+ch - 48);flag&&(res=-res);}
template<typename T>void Out(T x){if(x<0)putchar('-'),x=-x;if(x>9)Out(x/10);putchar(x%10+'0');}
int nex[maxn];
int a[maxn];
signed main()
{
    ios,cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i] , a[i] %= mod;
    for(int i = n ; i >= 1 ; i --) nex[i] = nex[i + 1] + a[i] , nex[i] %= mod;
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        ans += (nex[i + 1] * a[i]) % mod;
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}

/*
1
12
LLLLRRLRRRLL
*/
