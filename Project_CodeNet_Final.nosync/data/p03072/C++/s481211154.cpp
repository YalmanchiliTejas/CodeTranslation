#include<bits/stdc++.h>
int n, h, ans, m;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &h);
        if(m <= h){
            ans++; m = h;
        }
    }
    printf("%d\n", ans);
}