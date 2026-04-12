#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 ;
const int INF = 1e9 + 1e5 + 2;
const int mod= 1e9+7;
#define eps 1e-15
typedef long long ll;
int main()
{
    string s;

    cin>>s;

    bool a=0,b=0;
    for (int i=0; i<3; ++i)
    {
        if (s[i]=='B' && s[i+1]=='A')
            a=1;
        if (s[i]=='A' && s[i+1]=='B')
            a=1;
    }
    a?cout<<"Yes":cout<<"No";








}
