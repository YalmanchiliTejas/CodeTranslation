#include<bits/stdc++.h>
using namespace std;
long long a,b,c,kk;
int main()
{
    cin>>a>>b>>c;
    if(b>=a)//第一天到达
    {
        cout<<1<<endl;
        exit(0);//强制结束程序，子程序可用
    }
    if(c>=b)//出不去
    {
        cout<<-1<<endl;
        return 0;
    }
    if((a-b)%(b-c)>=1)kk=1;
    cout<<((a-b)/(b-c)+kk)*2+1<<endl;
}