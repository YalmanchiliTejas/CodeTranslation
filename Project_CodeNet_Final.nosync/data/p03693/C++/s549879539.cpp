#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
#define LINF (long long)4e18

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
   int r,g,b; cin >> r >> g >> b;
   int num = 100*r + 10*g + b;
   if(num % 4 == 0) cout << "YES" << endl;
   else cout << "NO" << endl;
}
