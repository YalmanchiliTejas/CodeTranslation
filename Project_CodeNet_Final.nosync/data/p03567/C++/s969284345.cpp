#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long int ull;
typedef vector<int> vi;
#define rep(i,a,n) for(int i = (a);i < (n);i++)
#define per(i,a,n) for(int i = (a);i > (n);i--)
#define lep(i,a,n) for(int i = (a);i <= (n);i++)
#define pel(i,a,n) for(int i = (a);i >= (n);i--)
#define all(v) (v).begin(),(v).end()
#define clr(a,b) memset((a),(b),sizeof(a))
#define sz size()
#define pb push_back
#define print(x) cout << x << endl
#define INF 1e+9+7
int n,m;
string s,t;

int main(){
  cin >> s;
  t = "No";
  rep(i,0,s.sz){
    if(s[i] == 'A' && s[i+1] == 'C'){
      t = "Yes";
    }
  }
  print(t);
  return 0;
}