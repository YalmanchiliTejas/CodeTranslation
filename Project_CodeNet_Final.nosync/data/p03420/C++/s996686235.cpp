#include <stdio.h>
int main(){
    long int n,k,cnt=0;
    scanf("%ld%ld",&n,&k);
    if(!k){
        printf("%ld\n",n*n);
        return 0;
    }
    for(long int i=k;++i-n-1;)cnt+=n/i*(i-k)+((n%i>=k)?n%i-k+1:0);
    printf("%ld\n",cnt);
    return 0;
}