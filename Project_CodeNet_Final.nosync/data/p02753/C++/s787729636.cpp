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
  string s;
  cin >> s;
  char c = s[0];
  if(s[1] == c&&s[2] == c){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
