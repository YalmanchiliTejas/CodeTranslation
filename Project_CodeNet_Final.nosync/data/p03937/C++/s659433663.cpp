#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)
//std::sort(v.begin(), v.end(), std::greater<Type>());
//set_intersection(x, x+7, y, y+6, back_inserter(v));
//set_union(x, x+7, y, y+6, back_inserter(v));
//set_difference(x, x+7, y, y+6, back_inserter(v));

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

bool isPrime(int n){
  if(n < 2) return false;
  else if(n == 2) return true;
  else if(n%2==0) return false;

  for(int i=3;i<=sqrt(n);i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  int h,w;
  int final = 0;
  cin >> h >> w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char tmp;
      cin >> tmp;
      if(tmp=='#' && j<final){
        cout<< "Impossible" <<endl;
        return 0;
      }
      if(tmp=='#') final = j;
    }
  }
  cout<< "Possible" <<endl;
}
