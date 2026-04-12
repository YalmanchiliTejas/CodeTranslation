#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<int >    vecint;
typedef vector<string > vecstr;
int main()
{
  int r, g, b;
  cin >> r >> g >> b;
  int c = 100*r + 10*g + b;
  if(c%4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
