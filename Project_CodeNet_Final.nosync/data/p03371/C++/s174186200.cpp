#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>

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

#define rep(i,x,y) for(int i=(x); i<(y); ++i)
const int INF = (1<<30);
const ll INFLL = 1LL<<62;
const long double EPS = 1e-12;

template <typename T>
void vec_print(vector<T> VEC){
  rep(i, 0, VEC.size()){
    cout << VEC[i] << " ";
  }
  cout << endl;
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  rep(i, 0, MAT.size()){
    rep(j, 0, MAT[i].size()){
      cout << MAT[i][j] << " ";
    }
    cout << endl;
  }
};

class HOGE{
  public:
    ll index;
    ll value;
    HOGE(ll index, ll value){
      this->index = index;
      this->value = value;
    };
    ~HOGE(void){
      return;
    };

    void print(void){
      cout << "index : " << index << ", value : " << value << endl;
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

int main(){
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll D, Z = min(X, Y);
  if(X > Y){
    D = A;
  }else{
    D = B;
  }

  ll ans=0;
  if(A + B <= 2*C){
    ans += (A+B)*Z;
  }else{
    ans += 2*C*Z;
  }

  if(D <= 2*C){
    ans += D*(max(X, Y)-Z);
  }else{
    ans += 2*C*(max(X, Y)-Z);
  }

  cout << ans << endl;

  return 0;
}