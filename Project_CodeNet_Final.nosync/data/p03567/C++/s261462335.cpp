#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
typedef long long ll;
using namespace std;
int main()
{
    string s;
    cin >> s;
    rep(i,0,s.length()-1)
    {
       if(s[i]=='A'&&s[i+1]=='C'){
          cout << "Yes" << endl;
          return 0;
       }
    }
    cout << "No" << endl;
}