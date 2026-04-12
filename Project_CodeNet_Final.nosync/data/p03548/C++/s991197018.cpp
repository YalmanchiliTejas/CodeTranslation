#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,sum;
    scanf("%d %d %d",&n,&a,&b);
    n-=b;
    sum=n/(a+b);
    cout<<sum<<endl;
    return 0;
}