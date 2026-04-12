#include<iostream>
#include<cstdio>
using namespace std;
const int x = 2e5+5;
int n, a[x];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = n - 1 ; i >= 0; i-=2){
        if(i!=n-1) printf(" ");
        printf("%d",a[i]);
    }
    int i = 0;
    if(n%2)i = 1;
    for(;i<n; i+=2){
       printf(" %d",a[i]);
    }
    printf("\n");
    return 0;
}