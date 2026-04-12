#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1012345678;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int gcd(int a, int b)
{
  if (a%b==0){
    return(b);
  }
  else{
    return(gcd(b,a%b));
  }
}

int main(){
  int N;
  cin >> N;
  int M = 0;
  int ans = 0;
  rep(i,N){
    int h;
    cin >> h;
    if(M <= h) ans++;
    M = max(M,h);
  }
  cout << ans << endl;
  return 0;
}


