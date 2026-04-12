#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(),x.end()
#define sz(x)   (int)x.size()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 1005;
const int   mod = 1e9 + 7;

void add(int&a,int b)   {
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub(int&a,int b)   {
    a -= b;
    if (a <  0)
        a += mod;
}
int mul(int a,int b)    {
    return  1ll * a * b % mod;
}
int Pow(int a,int b)    {
    int ans = 1;
    while (b)   {
        if(b & 1)   ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}
int inv(int a,int p)    {
    return  a == 1 ? 1 : p - 1ll * p * inv(p % a,a) / a;
}

int f[N];

int Fac[N];
int Inv[N];

typedef pair<int,int>   ii;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Fac[0] = Inv[0] = 1;

    for(int i = 1 ; i < N ; ++i)    Fac[i] = mul(Fac[i - 1],i);     Inv[N - 1] = inv(Fac[N - 1],mod);
    for(int i = N - 2 ; i ; --i)    Inv[i] = mul(Inv[i + 1],i + 1);

    int n;  cin >> n;
    int a, b;   cin >> a >> b;
    int c, d;   cin >> c >> d;

    f[0] = 1;

    for(int i = a ; i <= b ; ++i)   {
        int l = c;
        int r = min(d,n / i);

        for(int s = n ; s >= 0 ; --s)   {
            int x = Pow(Inv[i],l);

            for(int j = l ; j <= r ; ++j)   {
                if (i * j > s)
                    break;

                add(f[s],mul(mul(x,Inv[j]),f[s - i * j]));

                x = mul(x,Inv[i]);
            }
        }
    }

    int ans = f[n];

    for(int i = 1 ; i <= n ; ++i)
        ans = mul(ans,i);

    cout << ans << endl;
}
