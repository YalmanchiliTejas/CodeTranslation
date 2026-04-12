#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ten52 200005

int num[ten52];
int vint[ten52];

int main(void)
{
    int m,n,i,l,r;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        vint[i]=num[i]=m;
    }
    sort(vint,vint+n);
    l=vint[n/2-1];
    r=vint[n/2];
    for(i=0;i<n;i++)
    {
        if(num[i]>=r) cout<<l<<endl;
        else cout<<r<<endl;
    }
    return 0;
}

