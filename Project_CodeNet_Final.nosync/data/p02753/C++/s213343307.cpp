#include <bits/stdc++.h>
#define ll long long
const ll base = 31;
const ll MOD = 1e9+9;
const ll  maxN = 1e6+9;

using namespace std ;
int main()
{ string s;
 cin >> s;
 int a= 0,  b=0;
 for ( int i = 0 ;i < s.size() ; i++)
    if ( s[i]=='A' ) a++ ;
   else b++;
    if ( a == 2 || b==2) cout<<"Yes";else cout<<"No";
    return 0;
}
