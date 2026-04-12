#include<cstdio>
int a[200000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=n-1;i>=0;i-=2)printf("%d ",a[i]);
    for(int i=n%2;i<n;i+=2)printf("%d ",a[i]);
    return 0;
}