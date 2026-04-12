#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 1e7 + 5;
const int   mod = 998244353;

void add(int &a,int b)  {
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub(int &a,int b)  {
    a -= b;
    if (a <  0)
        a += mod;
}
int mul(int a,int b)    {
    return  1ll * a * b % mod;
}
int inv(int a,int p)    {
    return  a == 1 ? 1 : p - 1ll * p * inv(p % a,a) / a;
}

int Fac[N];
int Inv[N];
int Pow[N];

int Ckn(int n,int k)    {
    if (n < k)  return  0;
    if (k < 0)  return  0;

    return  mul(Fac[n],mul(Inv[k],Inv[n - k]));
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Fac[0] = Inv[0] = 1;

    for(int i = 1 ; i < N ; ++i)    Fac[i] = mul(Fac[i - 1],i);     Inv[N - 1] = inv(Fac[N - 1],mod);
    for(int i = N - 2 ; i ; --i)    Inv[i] = mul(Inv[i + 1],i + 1);

    int n;  cin >> n;

    int ans = Pow[0] = 1;

    for(int i = 1 ; i <= n ; ++i)   {
        ans = mul(ans,3);
        Pow[i] = mul(Pow[i - 1],2);
    }

    for(int i = n / 2 + 1 ; i <= n ; ++i)
        sub(ans,mul(Ckn(n,i),Pow[n - i + 1]));

    cout << ans << endl;
}