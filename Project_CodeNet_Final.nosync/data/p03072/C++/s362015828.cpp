#include<bits/stdc++.h>
using namespace std;
int n,arr[22],cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        int fl=0;
        for(int j=1;j<i;j++) if(arr[j] > arr[i]) fl=1;
        if(!fl) cnt++;
    }
    printf("%d",cnt);
}
