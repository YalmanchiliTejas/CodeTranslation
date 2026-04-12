#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[1000005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int r=250000;
    int l=250000;
    for(int i=0;i<n;i++){
        if(i==0){
            b[l--]=a[i];
        }
        if(i%2){
            b[l--]=a[i];

        }
        else{
            b[r++]=a[i];
        }

    }

    if(n%2==0){
        for(int i=l+1;i<r;i++){

            printf("%d",b[i]);
            if(i==r-1)
                puts("");
            else
                printf(" ");
        }
    }
    else{
        for(int i=r-1;i>l;i--){
            printf("%d",b[i]);
            if(i==l+1)
                puts("");
                else
                printf(" ");
        }

    }
}
