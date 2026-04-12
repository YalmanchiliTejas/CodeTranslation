#include<iostream>
#include<algorithm>
using namespace std;
long long int g,m,a[52][2]= {0},b[52]= {0},num=0;
int yun()
{
    int i,j;
    for(i=0; i<g; i++)
    {
        for(j=0; j<g; j++)
        {
            if(i==j)
                continue;
                a[j][1]+=a[i][0];
                a[j][0]+=a[j][1]/g;
                a[j][1]%=g;
        }
        num+=a[i][0];
        a[i][0]=0;
    }
}
int judge()
{
    int i,j,flag=0;
    for(i=0; i<g; i++)
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
    cin>>g;
    for(i=0; i<g; i++)
        cin>>b[i];
    for(i=0; i<g; i++)
    {
        a[i][0]=b[i]/g;
        a[i][1]=b[i]%g;
    }
    while(1)
    {
        if(judge()==0)
            break;
        yun();
    }
    cout<<num;
}