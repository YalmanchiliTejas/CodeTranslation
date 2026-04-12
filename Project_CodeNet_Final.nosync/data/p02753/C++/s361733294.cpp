#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
char a[1001][1001];
#define DADAH ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    DADAH

  string s;

  cin>>s;

  if(s=="AAA" or s=="BBB")cout<<"No";
  else cout<<"Yes";
    return 0;

}
