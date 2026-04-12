#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n;//由于数字可能很大，要开 long long 
int main()
{
    cin>>a>>b>>c;
    if(b>=a)
    {
        cout<<1<<endl;//第一天就爬上去了 
        exit(0);//快乐一生，可以停止了 
    }
    if(c>=b)
    {
        cout<<-1<<endl;//永远上不去了 
        return 0;//和外面的世界再见吧 
    }
    //没办法，还是要一系列计算其他结果 
    if((a-b)%(b-c)>=1) 
		n=1;//计算前判断一个特殊情况 
    cout<<((a-b)/(b-c)+n)*2+1<<endl;//其他的就只好按公式算出答案，输出
    return 0;//结束程序 
}