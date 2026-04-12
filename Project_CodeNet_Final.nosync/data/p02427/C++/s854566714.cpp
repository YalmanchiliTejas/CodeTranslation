#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        cout<<i<<":";
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1)cout<<" "<<j;
        }
        cout<<endl;
    }
}

