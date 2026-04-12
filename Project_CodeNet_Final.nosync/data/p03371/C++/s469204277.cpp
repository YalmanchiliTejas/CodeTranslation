#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<deque>

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define per(i, a, n)  for(int i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX 1000000001
using namespace std;
typedef long long ll;

int a,b,c;
int x,y;

int main(){
  std::cin >> a>>b>>c>>x>>y;
  int res = MAX;
  int tmp;
  rep(i,0,max(x,y)+1){
    tmp = a * max(0,(x-i))+ b * max(0,(y-i)) + 2*c*i;
    res = min(res, tmp);
  }

  std::cout << res << '\n';
}
