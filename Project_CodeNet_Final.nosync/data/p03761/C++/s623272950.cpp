#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;//见题目
string s;//只需要一个string轮流扫
int a[27];//26个字母出现的次数
int minn[27];//出现的最少次数
int main(){
    cin>>n;
    for(int i=1;i<=26;i++)minn[i]=10086;//附一个超大的值
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++)a[j]=0;//归零
        cin>>s;
        for(auto j:s)a[j-'a'+1]++;//重点！auto和for-range连用是最方便的
        for(int j=1;j<=26;j++)minn[j]=min(minn[j],a[j]);//更新最小值
    }
    for(int i=1;i<=26;i++)
        for(int j=1;j<=minn[i];j++)putchar('a'+i-1);//输出
}