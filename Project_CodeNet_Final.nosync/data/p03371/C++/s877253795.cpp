#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<map>
//#define ll long long
using namespace std;
const int maxn=100010;
int v[maxn];
int plate[maxn];

int main( )
{
    int a,b,c,x,y;
    long long sum;
    cin>>a>>b>>c>>x>>y;//一盒南方规则棋盘价格为A，一盒北方规则棋盘价格为B
                      //X盒适用南方规则的棋盘和Y盒北方规则的棋盘
    int k=min(x,y);
    if(2*c<a+b)
        sum=c*k*2;
    else
        sum=(a+b)*k;
   
    if(x>k)
    {
        if(2*c<a)
            sum+=2*c*(x-k);
        else
            sum+=a*(x-k);
    }
    if(y>k)
    {
        if(2*c<b)
            sum+=2*c*(y-k);
        else
            sum+=b*(y-k);
    }
    cout<<sum;
	 return 0;
}
