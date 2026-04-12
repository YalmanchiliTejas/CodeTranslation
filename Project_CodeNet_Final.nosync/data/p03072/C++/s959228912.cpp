#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <string>
#include <random>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 105;

int a[maxn];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  int ret = 0;
  int mx = -1;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(x>=mx)ret++;
    mx=max(x,mx);
  }
  cout<<ret<<endl;
  return 0;
}