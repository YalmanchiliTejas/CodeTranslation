#include<bits/stdc++.h>
#define   ll  long long int
#define   sz  1000100

using namespace std;

ll num[sz];
ll ara[sz];

int main()
{


    ll n,x,y,a,b,i,j,p,d,z,c=1;

    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>num[i];
    }

    ll m=n/2+1;

    ara[m]=num[1];
    i=m+1;
    j=m-1;

    for(x=2;x<=n;x++)
    {
        if(n%2==0)
        {
            if(c%2==1)
            {
                ara[j]=num[x];
                j--;
            }
            else
            {
                ara[i]=num[x];
                i++;
            }
        }
        else
        {
             if(c%2==0)
            {
                ara[j]=num[x];
                j--;
            }
            else
            {
                ara[i]=num[x];
                i++;
            }
        }
        c++;
    }


    for(i=1;i<n;i++)cout<<ara[i]<<" ";

    cout<<ara[n]<<endl;

    return 0;
}

