#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <string>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SORT(x) sort(x.begin(),x.end())
#define REVE(x) reverse(x.begin(),x.end())
#define all(x) (x).begin(),(x).end()
#define fst first
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define sw swap
#define FOR(i, m, n) for(int i = m;i < n;i++)
using LL = long long;
using ULL = unsigned long long;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
int main(){
    int N,x1,c=1;
     cin >> N >>x1;
      rep(i,N-1){
          int x2;
          cin >> x2;
        if (x1 <= x2){
          x1=x2;
        c++;
      }
    }
  cout <<c;
}