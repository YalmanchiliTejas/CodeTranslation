#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
using ll = long long;
using VI = vector<int>;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int count = 0;
  x-=z;
  while(x>0){
    x-=y;
    x-=z;
    count++;
  }
  cout << (x<0?count-1:count) << endl;
}
