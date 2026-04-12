#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(void){
    long long n,x,y,z;
    scanf("%lld",&n);
    long long a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    sort(a,a+n);
    y=a[(n/2)-1];
    z=a[n/2];
    for(int i=0;i<n;i++){
        if(b[i]<=y){
            printf("%lld\n",z);
        }else{
            printf("%lld\n",y);
        }
    }
}