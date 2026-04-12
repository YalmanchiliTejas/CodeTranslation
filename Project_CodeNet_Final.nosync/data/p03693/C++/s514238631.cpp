#include<cstdio>
#include<iostream>
using namespace std;


int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a*100+b*10+c;
    if(sum %4==0)
        printf("YES\n");
    else
        printf("NO\n");

}
