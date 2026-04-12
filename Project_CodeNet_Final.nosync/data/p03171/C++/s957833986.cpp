#include<bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
 
#define PII pair<LL,LL>
#define mem(v, x) memset(v, x, sizeof v)
 
#define si(x) scanf("%d", &x)
#define sii(x, y) scanf("%d %d", &x, &y)
#define siii(x, y, z) scanf("%d %d %d", &x, &y, &z)
 
#define sf(x) scanf("%lf", &x)
#define endl '\n'

#define FOR(i , N) for(int i = 0  ; i < N ; i++)
#define FOR1(i , N) for(int i = 1  ; i <= N ; i++)

template <typename T> T six(T &n){n = 0;bool neg = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') neg = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(neg) n = ~(n-1);return n;}

using namespace std;
 
typedef long long LL;
 
int SET(int N,int pos){return N=N | (1<<pos);}
int RESET(int N,int pos){return N= N & ~(1<<pos);}
bool CHECK(int N,int pos){return (bool)(N & (1<<pos));}

const int MOD = 1000000007;
#define PLL pair<LL, LL> 
const LL inf = 1e17;
/*
   D er iterative parlam na
   D te First WA Why???
   Probability Expected Value pari na
*/

LL add(LL x, LL y) {
   x %= MOD;
   y %= MOD;
   x += y;
   x %= MOD;
   return x;
}

int N;
int arr[3003];
PLL dp[3003][3003][2];

PLL rec(int st = 0, int en = N - 1, int sign = 1) {
  if(st > en) return {0,0};
  if(st == en) {
    if(sign) return PLL(arr[st], 0);
    return PLL(0, arr[st]);
  }
  PLL &ret = dp[st][en][sign];
  if(ret.fi != -1 && ret.se != -1) return ret;
  LL ans1 = -inf, ans2 = -inf;
  if(sign) {
      PLL p = rec(st + 1 , en, sign ^ 1);
      LL var1 = arr[st] + p.fi;
      if(ans1 < var1) {
        ans1 = var1;
        ans2 = p.se;
      }

      p = rec(st , en - 1, sign ^ 1);
      var1 = arr[en] + p.fi;
      if(ans1 < var1) {
        ans1 = var1;
        ans2 = p.se;
      }
  } else {
      PLL p = rec(st + 1, en, sign ^ 1);
      LL var1 = arr[st] + p.se;
      if(ans2 < var1) {
        ans2 = var1;
        ans1 = p.fi;
      }

      p = rec(st, en - 1, sign ^ 1);
      var1 = arr[en] + p.se;
      if(ans2 < var1) {
        ans2 = var1;
        ans1 = p.fi;
      }
  }
  ret = PLL(ans1, ans2);
  return ret = PLL(ans1, ans2);
}

int main()
{

#ifndef ONLINE_JUDGE // dont use this in toph/codemarshal
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    mem(dp , -1);
    cin >> N;
    FOR(i , N) cin >> arr[i];
    cout << rec(0, N-1).fi - rec(0, N - 1).se << endl;
}  
