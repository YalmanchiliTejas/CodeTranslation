#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = inf;
  for(int ab=0; ab <= 2*max(X,Y); ab+=2) {
	int x = max(0,X - ab/2);
	int y = max(0,Y - ab/2);
	int tmp = x * A + y * B + C * ab;
	ans = min(tmp, ans);
  }
  cout << ans << endl;
  
  return 0;
}

