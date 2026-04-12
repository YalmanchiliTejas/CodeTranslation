#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        bool flag=true;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>a[i])
            {
                flag=false;
                break;
            }


        }
        if(flag)
            cnt++;
    }
    cout<<cnt<<"\n";
}
