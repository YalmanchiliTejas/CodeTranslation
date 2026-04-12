#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >=0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

typedef long long ll;
#define INF 1e9

int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}



int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n){
    cin >> a[i];
  }
 
  if(n % 2==0){
    for(int i = n-1; i >= 0; i-=2){
      cout << a[i] << " ";
    }
    for(int j = 0; j < n; j+=2){
      cout << a[j];
      if(j!= n-1)
        cout << " ";
    }
  }
  else{
    for(int i = n-1; i >= 0; i-=2){
      cout << a[i] << " ";
    }
    for(int i = 1; i < n; i+=2){
      cout << a[i];
      if(i!= n-1)
        cout << " ";
    }
  }
  cout << endl;
  return 0;
}