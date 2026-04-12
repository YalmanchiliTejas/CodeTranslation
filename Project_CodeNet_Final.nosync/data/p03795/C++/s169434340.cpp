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
#define pob pop_back
#define sw swap
using LL = long long;
using ULL = unsigned long long;
#define FOR(i, m, n) for(int i = m;i <= n;i++)
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
int main(){
LL a=0,b=0,c=0;
cin >> a;
FOR(i,1,a){
b=800*i;
if(i%15==0){
    c+=200;
}
}
cout << b-c;
 return 0;
  }