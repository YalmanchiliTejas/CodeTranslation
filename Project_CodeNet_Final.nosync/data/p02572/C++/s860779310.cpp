#include <bits/stdc++.h>
using namespace std;

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

#define int                                       long long
#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)
#define rlop(i,e,s)                               for(int i=e;i>=s;i--)
#define prvec(v)                                  lop(R15,0,v.size())cout << v[R15] <<" "; cout << endl;
#define prarr(arr,s1,e1)                          lop(R15,s1,e1)cout << arr[R15] << " "; cout << endl;

#define endl                                      '\n'
#define ff                                        first
#define ss                                        second
#define pii                                       pair<int,int>

#define pb                                        push_back
#define all(v)                                    v.begin(),v.end()

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

const int N = 3e6 + 7, M = 1000000007, inf = INT_MAX;
const long long INF = LLONG_MAX;

inline int mul(int a, int b) { return (1ll * a * b) % M; };
inline int add(int a, int b)
{
      if ( a + b < 0 ) return a + b + M;
      if ( a + b >= M) return a + b - M;
      return a + b;
}


void solve()
{
      int n;
      cin >> n;
      int arr[n];

      vector<int> pre(n + 1, 0);

      lop(i, 0, n) cin >> arr[i];

      pre[n - 1] = arr[n - 1];
      rlop(i, n - 2, 0) pre[i] = arr[i] + pre[i + 1];

      int ans = 0;

      lop(i, 0, n - 1)
      {
            pre[i + 1] %= M;
            arr[i] %= M;
            int a1 = mul(arr[i], pre[i + 1]);
            ans = add(ans, a1);
      }

      cout << ans << endl;

}

int32_t main()
{
      ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);

      int test = 1;
      // cin >> test;
      while (test--)solve();


}



















