#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2])cout << "No" << endl;
  else{
    cout << "Yes" << endl;
  }
  system("pause");
}
