#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    long long int a,b,k;
    scanf("%lld%lld%lld",&k,&a,&b);
    if(k<=a)
    return puts("1"),0; //按思路特判
    else if(a<=b)
    return puts("-1"),0;   //按思路特判
    else 
    printf("%lld\n",((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1);
    return 0;
}