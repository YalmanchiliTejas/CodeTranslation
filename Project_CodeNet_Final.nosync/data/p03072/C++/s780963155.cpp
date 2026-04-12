#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define All(x) (x).begin(),(x).end()
using namespace std;
using pii  = pair<int,int>;
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

int main(){
  int a,b[1009],ma,c;
  ma=c=0;
   cin >> a;
  rep(i,a){
    cin >> b[i];
    if(b[i]>=ma){
      ma=b[i];
      c++;
    }
  }
  cout << c << endl;
}
