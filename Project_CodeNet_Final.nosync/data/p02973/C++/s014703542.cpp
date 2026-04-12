#include <iostream>
using namespace std;
const int N = 1e5+150;
int n,v[N],a[N],poz,i,j,k,st,dr,mij;
int main()
{
    cin>>n;
    for (i=1; i<=n; ++i)
        cin>>v[i];
    a[1]=v[1];
    k=1;
    for (i=2;i<=n;++i)
    {
        poz=0;
        st=1;dr=k;
        while (st<=dr)
        {
            mij=(st+dr)/2;
            if (v[i]>a[mij])
            {
                poz=mij;
                dr=mij-1;
            }
            else st=mij+1;
        }
        if (poz) a[poz]=v[i];
        else a[++k]=v[i];

    }
    cout<<k<<"\n";
}



