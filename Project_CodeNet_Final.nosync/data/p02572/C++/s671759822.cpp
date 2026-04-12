
// Problem: C - Sum of product of pairs
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)



    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define FAST ios_base::sync_with_stdio(false);cin.tie(0);
    const double EPS = 1e-9;
    const double PI = acos(-1);
    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
    //const int dx[]={0,0,0,1,1,1,-1,-1,-1};
    //const int dy[]={-1,0,1,-1,0,1,-1,0,1};
    const int dx[] = {0 , 1 , 0 , -1};
    const int dy[] = {1 , 0 , -1 , 0};
    //#define MOD         1000000007LL
    #define MAX         1000005
    const ll MOD = 1000000000 + 7;
    ll mod(ll x)
    {
        return ((x % MOD) + MOD) % MOD;
    }
    
    ll add(ll a , ll b)
    {
        return mod(mod(a) + mod(b));
    }
    
    ll mul(ll a , ll b)
    {
        return mod(mod(a) * mod(b));
    }
    
    
    int main()
    {
        FAST
        int t;
        t = 1;

        while(t--)
        {
           int n ;
           cin >> n;
           
           vector<ll> arr(n + 5 , 0) , sum(n + 5 , 0);
           
           for(int i = 1 ; i <= n ; i++)
           {
               cin >> arr[i];
               sum[i] = arr[i];
           }
           
           for(int i = 1 ; i <= n ; i++)
           {
               sum[i] += sum[i - 1];
               sum[i] %= MOD;
           }
           
           ll s = 0;
           
           for(int i = 1 ; i < n  ; i++)
           {
               s = add(s , mul(arr[i] , sum[n] - sum[i]));
           }
           
           cout << s << endl;
        }
    }

