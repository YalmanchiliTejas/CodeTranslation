#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = (a); i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  string s;
  cin >> s;
  int flag=1;
  if(s[0]==s[1]&&s[1]==s[2]) flag = 0;
  cout << (flag?"Yes":"No") << endl;
  return 0;
}