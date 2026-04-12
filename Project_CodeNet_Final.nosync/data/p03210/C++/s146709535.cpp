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
//　ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1012345678;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int gcd(int a, int b){
  if (a%b==0){
    return(b);
  }
  else{
    return(gcd(b,a%b));
  }
}


int ans[1000000];
int sum[1000000];

int main(){
  int X;
  cin >> X;
  if(X == 3||X==5||X==7) cout << "YES" << endl;
  else cout << "NO" << endl;
}


