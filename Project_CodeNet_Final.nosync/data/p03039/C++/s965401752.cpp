#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3LL;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 2*(int)1e5 + 10;

const int mod = 1000000007;

int fact[N], ifact[N];

int power(int a, int b, int m = mod){a %= m; if(b < 0)b += m-1; int r = 1; while(b){if(b&1)r=(r*a)%m; a = (a*a)%m; b>>=1;}return r;}

void pre(){
   fact[0] = 1;
   for (int i = 1; i < N; ++i)
   {
      fact[i] = (fact[i-1] * i) % mod;
   }

   for (int i = 0; i < N; ++i)
   {
      ifact[i] = power(fact[i], -1) % mod; 
   }
}

int nCr(int n, int r){
   if(r > n or r < 0 or n < 0)
      return 0;
   int one = (ifact[n-r] * ifact[r]) % mod;
   int two = fact[n];
   int ans = one * two % mod;
   return ans;
}

vector<int> X, Y;

int getAns(vector<int> arr){
   sort(arr.begin(), arr.end());
   int ans = 0;
   int sum = 0;
   for (int i = 0; i < sz(arr); ++i)
   {
      ans += (arr[i]) * i - sum;
      sum += (arr[i]);
   }
   return ans;
}

void solve(int N, int M, int K){
   pre();

   for (int i = 1; i <= N; ++i)
   {
      for (int j = 1; j <= M; ++j)
      {
         X.push_back(i);
         Y.push_back(j);
      }
   }

   int A = getAns(X);
   int B = getAns(Y);

   int C = (A + B) % mod;

   int tot = nCr(N*M-2, K-2) * C;
   tot %= mod;

   cout<<tot;
}

int32_t main(){_
    int N;
    cin >> N;
    int M;
    cin >> M;
    int K;
    cin >> K;
    solve(N, M, K);
    return 0;
}