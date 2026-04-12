#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,k,a,b,c,d,n;
    vector <long long int> v2;
    cin>>n;
    j=0;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v2.push_back(a);
    }
    if(n%2==0)
    {
        if(n>2)
         a=2;
        else
          a=-1;
        b=n-1;
        while(b>=1)
       {
        cout<<v2[b];
        b-=2;
        cout<<" ";
       }
       cout<<v2[0]<<" ";
       while(a<n)
       {
           cout<<v2[a];
           a+=2;
           if(a!=(n-1))
            cout<<" ";
       }
       cout<<"\n";
    }
    else
    {
        a=n-1;
        if(n>1)
            b=1;
        else
            b=-1;
        while(a>=2)
        {
            cout<<v2[a];
            a-=2;
            cout<<" ";
        }
        cout<<v2[0]<<" ";
        while(b<n && b!=-1)
        {
            cout<<v2[b];
            b+=2;
            if(b!=(n-1))
                cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
