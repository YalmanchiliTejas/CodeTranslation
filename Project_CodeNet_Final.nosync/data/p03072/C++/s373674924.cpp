#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define INF 999999999
typedef long long int Int;
using ll = long long;
using VI = vector<int>;
int main(){
  int n;cin >> n;
  int a;cin >> a;
  int max = a;
  int ans = 1;
  rep(i,n-1){
    int a;cin >> a;
    if(max<=a){
      ans++;
      max = a;
    }
  }
  cout << ans << endl;
}
