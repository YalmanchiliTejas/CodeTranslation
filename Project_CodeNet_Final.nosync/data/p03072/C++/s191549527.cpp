#include<bits/stdc++.h>
using namespace std;
int n,mx,cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        if(a>=mx){
            cnt++;
            mx=a;
        }
    }
    printf("%d",cnt);
}
