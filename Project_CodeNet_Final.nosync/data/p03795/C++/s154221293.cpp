#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int a,ans;
int main()
{
    cin>>a;
    if(a>=15)
        cout<<a*800-(a/15)*200;
    else
        cout<<a*800;
}


