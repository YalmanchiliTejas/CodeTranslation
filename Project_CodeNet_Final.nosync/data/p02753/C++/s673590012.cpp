#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("t5.in","r",stdin);
   //freopen("t5.out","w",stdout);
    int i,j,n,m;
    int flag1=0,flag2=0;
    string x;
    cin>>x;
    for(i=0;i<3;i++)
    {
        if(x[i]=='A')flag1=1;
        else flag2=1;
    }
    if(flag1&&flag2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
