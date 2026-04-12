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


/*
   D er iterative parlam na
   D te First WA Why???
   Probability Expected Value pari na
*/

LL add(LL x, LL y) {
   x %= 1000000007;
   y %= 1000000007;
   x += y;
   x %= 1000000007;
   return x;
}

string digit;
int D;
LL dp[2][2][10001][101];

LL digitDP(bool start = true, bool small = false, int pos = 0, int dv = 0) 
{
   if(pos == (int) digit.size()) {
      // cout << dv << endl;
      return (dv == 0) * 1LL;
   }
   LL &ret = dp[start][small][pos][dv];
   if(ret != -1) return ret;
   int dg = digit[pos] - '0';
   int maxx = (small == true) ? 9 : dg;
   LL ans = 0;
   for(int i = (start == true) ; i <= maxx ; i++)
      ans = add(ans, digitDP(false, small || (i < dg), pos + 1, (dv+ i) % D));
   if(start) ans = add(ans, digitDP(true, true, pos + 1, 0));
   return ret = ans % 1000000007;
}

LL solve()  {
   memset(dp, -1, sizeof dp);
   return digitDP(); // don’t count All zero (000....) case..
   // if you wanna count that, add a one :) 
}

int main()
{

#ifndef ONLINE_JUDGE // dont use this in toph/codemarshal
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    cin >> digit;
    cin >> D;
    cout << (((solve() % 1000000007) - 1 + 1000000007) % 1000000007) << endl;
}  
