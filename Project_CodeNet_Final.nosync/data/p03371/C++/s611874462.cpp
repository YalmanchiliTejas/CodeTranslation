#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
// #include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INFI = 1000000007;


int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int sum=A*X+B*Y;
  int ans=sum;
  int x=X,y=Y;
  for(int i=1; i<=max(X,Y); i++){
    int res=sum;
    res += C*2;
    if(x>0){
      res -= A;
    }
    if(y>0){
      res -= B;
    }
    ans = min(ans,res);
    sum = res;
    x--;
    y--;
  }
  cout << ans << endl;
  return 0;
}
