#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll, int> plli;
typedef pair<int, pii> pipii;
typedef vector<vector<int> > mati;
typedef vector<vector<double> > matd;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

#define rep(i,x,y) for(int i=(x); i<(y); ++i)

template <typename T>
void vec_print(vector<T> VEC){
  rep(i, 0, VEC.size()){
    cout << VEC[i] << " ";
  }
  cout << "\n";
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  rep(i, 0, MAT.size()){
    rep(j, 0, MAT[i].size()){
      cout << MAT[i][j] << " ";
    }
    cout << "\n";
  }
};

template <typename CLASS1, typename CLASS2>
class HOGE{
  public:
    CLASS1 key;
    CLASS2 value;
    HOGE(ll key, ll value){
      this->key = index;
      this->value = value;
    };
    ~HOGE(void){
      return;
    };

    void print(void){
      cout << "key : " << key << ", value : " << value << "\n";
      return;
    };
    
    bool operator==(const HOGE &obj){
      return (this->value == obj.value);
    };
    bool operator<(const HOGE &obj){
      return (this->value < obj.value);
    };
    bool operator>(const HOGE &obj){
      return (this->value > obj.value);
    };
};

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;

ll a[3000];
ll dp[3000][3000];

//ll Taro_search(const int, const int, const vll&, vvll&);
//ll Jiro_search(const int, const int, const vll&, vvll&);
//ll Taro_search(const int, const int);
//ll Jiro_search(const int, const int);

/*
ll Jiro_search(const int start, const int end, const vll& a, vvll& dp){
  if(start>end) return dp[start][end]=0;
  if(start==end) return dp[start][end]=-a[start];
  if(dp[start][end]>=0) return dp[start][end];

  ll tmp1 = Taro_search(start+1, end, a, dp) - a[start];
  ll tmp2 = Taro_search(start, end-1, a, dp) - a[end];
  return dp[start][end] = min(tmp1, tmp2);
}

ll Taro_search(const int start, const int end, const vll& a, vvll& dp){
  if(start>end) return dp[start][end]=0;
  if(start==end) return dp[start][end]=a[start];
  if(dp[start][end]>=0) return dp[start][end];

  ll tmp1 = Jiro_search(start+1, end, a, dp) + a[start];
  ll tmp2 = Jiro_search(start, end-1, a, dp) + a[end];
  return dp[start][end] = max(tmp1, tmp2);
}
*/

/*
ll Jiro_search(const int start, const int end){
  if(start>end) return dp[start][end]=0;
  if(start==end) return dp[start][end]=-a[start];
  if(dp[start][end]>=0) return dp[start][end];

  ll tmp1 = Taro_search(start+1, end) - a[start];
  ll tmp2 = Taro_search(start, end-1) - a[end];
  return dp[start][end] = min(tmp1, tmp2);
}

ll Taro_search(const int start, const int end){
  if(start>end) return dp[start][end]=0;
  if(start==end) return dp[start][end]=a[start];
  if(dp[start][end]>=0) return dp[start][end];

  ll tmp1 = Jiro_search(start+1, end) + a[start];
  ll tmp2 = Jiro_search(start, end-1) + a[end];
  return dp[start][end] = max(tmp1, tmp2);
}
*/

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll N;
  cin >> N;
  //vll a(N);
  rep(i, 0, N){
    cin >> a[i];
  }

  //vvll dp(N, vll(N, -1));
  memset(dp, -1, sizeof(dp));

  //ll ans = Taro_search(0, N-1, a, dp);
  //ll ans = Taro_search(0, N-1);

  int flag = (N%2==1 ? 1 : -1);
  rep(start, 0, N){
    dp[start][start] = flag*a[start];
  }

  rep(diff, 1, N){
    flag*=-1;
    if(flag==1){
      rep(start, 0, N-diff){
        dp[start][start+diff] = max(a[start]+dp[start+1][start+diff], dp[start][start+diff-1]+a[start+diff]);
      }
    }else{
      rep(start, 0, N-diff){
        dp[start][start+diff] = min(-a[start]+dp[start+1][start+diff], dp[start][start+diff-1]-a[start+diff]);
      }
    }
  }

  cout << dp[0][N-1] << endl;

  return 0;
}
