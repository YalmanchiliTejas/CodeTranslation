#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define pb push_back
using namespace std;
const int INF = 1e9;
typedef long long ll;

int main(){
  ll x,y,z;
  cin >> x >> y>> z;
  ll sum = 0;
  x -= z;
  while(1){
    if(x-y-z < 0)
      break;
    x -= y;
    sum++;
    x -= z;
  }
  cout << sum << endl;
  return 0;
}
