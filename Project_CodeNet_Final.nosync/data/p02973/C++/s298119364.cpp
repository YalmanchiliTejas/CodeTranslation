#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int num[100009]={0},a[100009]={0},f=0;
int main()
{
    int n,i,mi;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int n1;
        scanf("%d",&n1);
        num[i]=n1;
    }
    a[1]=num[1];
    f++;
    mi=a[1];
    for(i=2;i<=n;i++){
        if(num[i]<=mi){
            mi=num[i];
            a[++f]=num[i];
        }
        else{
                for(int j=1;j<=f;j++){
                    if(a[j]<num[i]){
                        a[j]=num[i];
                        if(j==f)
                            mi=num[i];
                            break;
                    }
                }
        }
        //printf("%d  %d\n",mi,f);

    }
    printf("%d\n",f);

    return 0;
}
