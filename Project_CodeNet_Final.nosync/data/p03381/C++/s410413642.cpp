#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
const int INF = 1 << 20;

typedef long long ll;




int main(){
  int n;
  cin >> n;
  vector <int> a;
  vector <int> b;
  REP(i,n){

    int c;
    cin >> c;
    a.pb(c);
    b.pb(c);
    
  }
  sort(b.begin(),b.end());
  int f,t;
  f = b.size()/2 - 1;
  t = f+1;

  REP(i,n){
    if(a[i] <= b[f]){
      cout << b[t] << endl;
    }
    else if(a[i] >= b[t]){
      cout << b[f] << endl;
    }
  }

  return 0;
}
