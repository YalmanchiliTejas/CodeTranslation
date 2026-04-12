#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,t,a,b,n,c,d,y,temp,m,r,sum,count,k,l,ans;
    t=1;
    // cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>a>>b>>d;
        a-=2*d;
        i=1;
        while(i)
        {
            if(a<(i*b)+(i-1)*d)
            break;
            i++;
        }
        cout<<--i;
    }
}