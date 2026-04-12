#include<iostream>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<vector>
#include<cmath>
#include<algorithm>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=b-1; i>=a; i--)
#define REP(i, n) for(int i=0; i<n; i++)
#define rREP(i, n) for(int i=n-1; i>=0; i--)
#define MAX 100001
typedef long long ll;
using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  cout << (x-z)/(y+z) << endl;
  return 0;
}
