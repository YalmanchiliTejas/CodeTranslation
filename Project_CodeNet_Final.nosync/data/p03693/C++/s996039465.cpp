#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <functional>
#include <list>
#include <utility>
#include<map>
#include<vector>
using namespace std;

typedef long long ll;
typedef long double ld;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)

#define get_arsize(a) (sizeof(a)/sizeof(a[0]))
const ll mod = 1000000007;
const double eps = 1e-10;
const int MAX = 200000;

int main() {
	int r,g,b;
	cin >> r >> g >> b;
  string a="YES";
  if ((r*100+g*10+b)%4) a = "NO";
  cout << a << endl;
  return 0;
}