#include<iostream>
#include<string>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(a,b) (a += b,b = a - b,a -= b)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x,y,z;
  int ct=0;
  cin >> x >> y >> z;
  int sum = z;
  while(1){
      if(sum+y+z<=x){
        sum = sum + y + z;
        ct++;
      }
      else break;
  }
  cout << ct << endl;
}
