#include "bits/stdc++.h"
using namespace std;
#define all(v) (v).begin(), (v).end()
#define io ios::sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rson rt << 1 | 1, mid + 1, r
#define lson rt << 1, l, mid
#define lll __int128
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eps 1e-12
#define int long long
const int mod = 1e9 + 7;
inline int ksm(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ans = ans * a % mod;
    return ans;
}

signed main()
{
    io;
    string s;cin>>s;
    int c1=0,c2=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')c1++;
        else c2++;
    }
    if(c1 && c2)cout<<"Yes";
    else cout<<"No";
    getchar(); //
    getchar();
}
