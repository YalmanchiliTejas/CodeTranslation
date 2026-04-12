#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
 string str; cin>>str; if(str[0]=='A' && str[1]=='B')cout<<"Yes";
 else if(str[0]=='B' && str[1]=='A')cout<<"Yes";
 else if(str[1]=='A' && str[2]=='B')cout<<"Yes";
 else if(str[1]=='B' && str[2]=='A')cout<<"Yes";
 else cout<<"No";
}


