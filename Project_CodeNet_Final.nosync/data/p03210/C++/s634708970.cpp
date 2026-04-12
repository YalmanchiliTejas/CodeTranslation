#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    int x;
    cin >> x;

    string ans="NO";
    if(x==3||x==5||x==7) ans="YES";

    cout << ans << endl;

   return 0;
}