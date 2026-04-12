#include<cstdio>
long long a,b,k;
main(){
    scanf("%lld%lld%lld",&k,&a,&b);
    if(k<=a)return puts("1"),0; //按思路特判
    else if(a<=b)return puts("-1"),0;   //按思路特判
    else printf("%lld\n",((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1);
    //按思路求解，此处的位运算 <<1 = *2 , |1 = +1
}