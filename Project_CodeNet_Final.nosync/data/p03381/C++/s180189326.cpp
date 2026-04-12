#include<bits/stdc++.h>
using namespace std;

struct fq
{
    int x;
    int mid;
    int h_h;
}a[200005];

int comp_1(fq a,fq b)
{
    return a.x<b.x;
}

int comp_2(fq a,fq b)
{
    return a.h_h<b.h_h;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x;
        a[i].h_h=i;
    }
    sort(a,a+n,comp_1);
    int flag=n/2;
    for(int i=0;i<n;i++)
    {
        if(a[i].x<a[flag].x)
            a[i].mid=a[flag].x;
        else
            a[i].mid=a[flag-1].x;
    }
    sort(a,a+n,comp_2);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].mid<<endl;
    }
    return 0;
}
