#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <map> // pair
#include <numeric> // accumulate(begin,end,初期値)
#include <string>
#include <cstdio>
#include <queue>
#include <stack>
#include <set>
#include <cmath>

typedef long long ll;
using namespace std;

#define FALSE printf("false\n");
#define TRUE printf("true\n");
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<x<<endl
#define rep(i,n) for(int i = 0;i < ((int)(n));++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SUM(vec) accumulate(all(vec),0)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define test(a) cout<<#a<<':'<<a<<endl

const ll INF = 1e9+7;

// 各桁の和
template<typename T>inline T digit(T num){T sum = 0;while(num){sum+=num%10;num/=10;}return sum;}
template<typename T>inline T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<typename T>inline T lcm(T a, T b){T g = gcd(a,b);return a/g*b;}
template<typename T>inline T power(T a,T b){T tmp=1;rep(i,b){tmp*=a;}return tmp;}


class tree{
public:
  tree* par;
  vector<tree*> chi;
  int cnt;
};

int cnt(int a,int b){
  int count = -1;
  while(a){
    a /= b;
    ++count;
  }
  return count;
}


int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int h,w;cin>>h>>w;
  vector<string> a(h);rep(i,h)cin>>a[i];
  rep(i,h){
    bool all_white = a[i].find("#") == string::npos;
    if(all_white){
      a.erase(a.begin()+i);
      --i;--h;
    }
  }


  rep(i,w){
    bool all_white = true;
    rep(j,h){
      all_white &= a[j][i] != '#';
    }
    if(all_white){
      rep(j,h){
        a[j].erase(a[j].begin()+i);
      }
      --i;--w;
    }
  }

  rep(i,h){
    print(a[i]);
  }
  return 0;
}