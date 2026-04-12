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
  int h;
  cin >> h;
  int w;
  cin >> w;
  vector<string> a(h);
  for(int i=0;i<h;i++){
    cin >> a[i];
  }
  vector<bool> row(h,false);
  vector<bool> col(w,false);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(row[i]){
      for(int j=0;j<w;j++){
        if(col[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}
