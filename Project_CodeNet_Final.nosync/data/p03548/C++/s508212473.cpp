#include<bits/stdc++.h>//头文件
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    a-=c;//减去空隙
    cout<<a/(b+c)<<endl;//除以人和空隙
    return 0;//结束
}