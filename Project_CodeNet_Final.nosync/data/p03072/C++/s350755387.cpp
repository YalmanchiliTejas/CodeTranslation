#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,h[25]={0},i,j,sum=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>h[i];
    for(i=1;i<=n;i++){
            int flag=1;
        for(j=0;j<i;j++)
        if(h[i]<h[j]) flag=0;
        if(flag==1) sum++;}
    cout<<sum;
    return 0;
}
