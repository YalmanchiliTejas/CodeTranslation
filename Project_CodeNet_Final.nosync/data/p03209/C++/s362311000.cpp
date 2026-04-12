#include<cstdio>
inline long long sum_layer(int n){
    return (1LL<<(n+2))-3;
}
inline long long sum_patty(int n){
    return (1LL<<(n+1))-1;
}
long long num_patty(int n,long long x){
    if(x==0)return 0;
    if(n==0)return 1;
    if(x<=sum_layer(n-1)+1)return num_patty(n-1,x-1);
    return sum_patty(n-1)+1+num_patty(n-1,x-sum_layer(n-1)-2);
}
int main(){
    int n;
    long long x;
    scanf("%d%lld",&n,&x);
    printf("%lld",num_patty(n,x));
    return 0;
}