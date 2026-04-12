#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;//定义
    cin>>n;
    x=n*800;//根据n求出x
    y=(n/15)*200;//根据n求出y
    cout<<x-y<<endl;//最后输出答案
    return 0;
}