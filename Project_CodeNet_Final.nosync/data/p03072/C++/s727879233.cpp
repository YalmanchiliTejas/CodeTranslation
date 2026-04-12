#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int main()
{
    int n,a[100],i,j,flag,s=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(j=0;j<n;j++)
    {
        flag=0;
        for(i=0;i<j;i++)
        {
            if(a[i]>a[j])
            {flag=1;break;}
        }
        if(flag==0)
            s++;
    }
    cout<<s<<endl;
    return 0;
}
