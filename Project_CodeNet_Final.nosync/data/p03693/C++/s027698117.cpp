#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main() 
{
  int a, b, c; cin >> a >> b >> c;
  if((a*100+b*10+c)%4 == 0){
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
  system("pause");
}