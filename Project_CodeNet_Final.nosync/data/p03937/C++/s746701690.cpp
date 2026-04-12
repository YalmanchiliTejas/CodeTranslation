#include <cmath>
#include <cstdio>
#include <vector>
#include<cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long t,i,n,m,mii[10],mxi[10],j,flag=0;
    char a[10][10];
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        mii[i]=10000;
        mxi[i]=-1;
    }
    for(i=0;i<n;i++)
    {
         for(j=0;j<m;j++)
         {
             cin>>a[i][j];
             if(a[i][j]=='#')
             {
                 //cout<<mxi[i]<<" "<<j<<endl;
                 mii[i]=min(mii[i],j);
                 mxi[i]=max(mxi[i],j);
             }
         }    
        if(i!=0)
        {
            
            if(!(mii[i]==mxi[i-1]))
            {
                //cout<<i<<" "<<mxi[i-1]<<" "<<mii[i]<<endl;
                flag=1;
            }
        }
    }
    //for(i=0;i<n;i++)
    //    cout<<mii[i]<<" "<<mxi[i]<<endl;
    if(!flag)
        cout<<"Possible"<<endl;
    else
        cout<<"Impossible"<<endl;
}