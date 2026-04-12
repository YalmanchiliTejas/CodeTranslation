#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int sum;
int main()
{
    cin>>a>>b>>c;
    sum=a*100+b*10+c;
    if(sum%4==0)
        printf("YES\n");
    else
        printf("NO\n");
}