#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int x,b,c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    cin>>x>>b>>c;
    x=x*100+b*10+c;
    if(x%4==0)
        cout<<"YES";
    else
        cout<<"NO";
    
}


