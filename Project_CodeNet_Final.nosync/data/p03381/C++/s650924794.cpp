#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    int mid=b[(n/2-1)];
    int midn=b[(n/2)];
    for(int i=0;i<n;i++){
        if(a[i]<=mid){
            printf("%d\n",midn);
        }
        else
           printf("%d\n",mid);
    }

}