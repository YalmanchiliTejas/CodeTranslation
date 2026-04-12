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

#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)

template <typename T>
void vec_print(vector<T> VEC){
  REP(i, VEC.size()){
    cout << VEC[i] << " ";
  }
  cout << "\n";
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  REP(i, MAT.size()){
    REP(j, MAT[i].size()){
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
    HOGE(void){
      return;
    };
    HOGE(CLASS1 key, CLASS2 value){
      this->key = key;
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

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll X;
  cin >> X;
  if(X==3 || X==5 || X==7){
    cout << "YES" << "\n";
  }else{
    cout << "NO" << "\n";
  }

  return 0;
}