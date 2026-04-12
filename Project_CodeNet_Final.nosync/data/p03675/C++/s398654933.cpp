#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010


int main(){
  int n;
  int a[SIZE];

  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }

  int cn = 0;

  vector<int> ans;
  
  for(int i=n/2*2;i>0;i-=2){
    ans.push_back(a[i-1]);
  }
  for(int i=1;i<=n;i+=2){
    ans.push_back(a[i-1]);
  }

  if(n%2) reverse(ans.begin(),ans.end());

  for(int i=0;i<n;i++){
    printf("%d%c",ans[i], " \n"[i==n-1]);
  }
  
  return 0;
}
