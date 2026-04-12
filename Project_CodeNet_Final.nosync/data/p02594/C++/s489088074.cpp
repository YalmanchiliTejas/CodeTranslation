#include<bits/stdc++.h>
using namespace std;
int main1()
{
    int a[1000],n,c=0,p;
    a[0]=1;
    cout<<"Enter a Number: ";
    cin>>n;//100
    
    while(n>=2)
    {
        p=0;
        for(int i=0;i<=c;i++)
        {
            p=(a[i]*n)+p;
            a[i]=p%10;
            p/=10;
        }
        
        while(p>0)
        {
            a[++c]=p%10;
            p/=10;
        }
        
        n--; 
    }
    
    for(int i=c;i>=0;i--)
    {
        cout<<a[i];
    }
}


int main()
{
    int x;cin>>x;
    x>=30?cout<<"Yes\n":cout<<"No\n";
}