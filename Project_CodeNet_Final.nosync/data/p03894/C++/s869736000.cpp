#include <bits/stdc++.h>
using namespace std;
int n,i,j,v[100010],ok[100010],curent,q,a,b;
int main()
{
    cin>>n;
    ok[1]=ok[2]=1;
    for(i=1;i<=n;i++)
        v[i]=i;
    curent=1;
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>a>>b;
        if(a==curent)
            curent=b;
        else if(b==curent)
            curent=a;
        swap(v[a],v[b]);
        if(curent>1)
            ok[v[curent-1]]=1;
        if(curent<n)
            ok[v[curent+1]]=1;
    }
    cout<<count(ok+1,ok+n+1,1);
    return 0;
}