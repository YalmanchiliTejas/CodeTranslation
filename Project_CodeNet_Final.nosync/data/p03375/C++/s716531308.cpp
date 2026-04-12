#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 3005;

int mod;
int f[N][N];
int C[N][N];

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
int mul(int a,int b)    {   return  1ll * a * b % mod;  }
int inv(int a,int p)    {   return  a == 1 ? 1 : p - 1ll * p * inv(p % a,a) / a;    }

int Pow(int a,int b)    {
    int ans = 1;
    while  (b)  {
        if (b & 1)  ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}
int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n >> mod;

    for(int i = 0 ; i <= n ; ++i)
        f[i][0] = 1,
        C[i][0] = 1;

    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= i ; ++j)
        add(f[i][j],mul(f[i - 1][j],j)),    //i is in one of given j group
        add(f[i][j],f[i - 1][j]),           //i is in no given group
        add(f[i][j],f[i - 1][j - 1]),       //i is in a new group

        add(C[i][j],C[i - 1][j]),
        add(C[i][j],C[i - 1][j - 1]);

    int ans = 0;

    for(int i = 0 ; i <= n ; ++i)   {
        mod--;  int E = Pow(2,n - i);
        mod++;  int F = Pow(2,n - i);

        int cur = 0;
        int val = 1;

        for(int j = 0 ; j <= i ; ++j)   {
            add(cur,mul(val,f[i][j]));
            val  =  mul(val,F);
        }

        cur = mul(cur,Pow(2,E));
        cur = mul(cur,C[n][i]);

        if (i & 1)  sub(ans,cur);
        else        add(ans,cur);
    }
    cout << ans << endl;
}