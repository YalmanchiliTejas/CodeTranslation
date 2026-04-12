#include<bits/stdc++.h>
using namespace std;
int n, s[100005];
long long ans, tmp;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", s+i);
    n--;
    for(int i = 1; i < n; i++){
        tmp = 0;
        for(int j = i; j + (n%i ? i : j) < n; j += i){
            ans = max(ans, tmp += s[j] + s[n-j]);
        }
    }
    printf("%lld\n", ans);
}