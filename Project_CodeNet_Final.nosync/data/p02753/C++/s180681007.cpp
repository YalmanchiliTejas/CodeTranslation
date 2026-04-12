#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    if((s[0]== 'A' and s[1]=='B') || (s[1]== 'A' and s[2]=='B' ) || (s[0]== 'B' and s[1]=='A') ||  (s[2]== 'A' and s[1]=='B'))cout<<"Yes";
    else cout<<"No";
   return 0;
}
 