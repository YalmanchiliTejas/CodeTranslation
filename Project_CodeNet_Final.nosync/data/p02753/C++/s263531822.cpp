#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+2;
string s,p;

int main()
{
    ft
    int t,i,j,n,m,l=0,r=0;
    cin>>s;
    for(char c:s)
    {
        if(c=='A')
        {
            l=1;
        }
        else
        {
            r=1;
        }
    }
    if(l==1 && r==1)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}

