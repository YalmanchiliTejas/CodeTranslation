#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans=0;
    for(int i=0;i<3;i++){
        scanf("%d",&n);
        ans*=10;
        ans+=n;
    }
    if(ans%4)
        printf("NO\n");
    else
        printf("YES\n");

}
