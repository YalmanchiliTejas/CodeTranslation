#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    long long n,i,j;
    scanf(" %lld",&n);

    for(i=0;i<n;i++){
        scanf(" %lld",&a[i]);
    }
    for(i=n-1;i>=0;i-=2){
        printf("%lld ",a[i]);
    }
    if(n%2==1){
        for(i=1;i<n;i+=2){
            printf("%lld ",a[i]);
        }
    }
    else{
        for(i=0;i<n;i+=2){
            printf("%lld ",a[i]);
        }
    }
    return 0;
}
