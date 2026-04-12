#include<iostream>
#include<algorithm>
using namespace std;
long long int n,m,a[52][2]= {0},b[52]= {0},num=0;
int yun()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
                continue;
                a[j][1]+=a[i][0];
                a[j][0]+=a[j][1]/n;
                a[j][1]%=n;
        }
        num+=a[i][0];
        a[i][0]=0;
    }
}
int judge()
{
    int i,j,flag=0;
    for(i=0; i<n; i++)
        if(a[i][0]!=0)
        {
            flag=1;
            break;
        }
    return flag;
}
int main()
{
    int i,j;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>b[i];
    for(i=0; i<n; i++)
    {
        a[i][0]=b[i]/n;
        a[i][1]=b[i]%n;
    }
    while(1)
    {
        if(judge()==0)
            break;
        yun();
    }
    cout<<num;
}
