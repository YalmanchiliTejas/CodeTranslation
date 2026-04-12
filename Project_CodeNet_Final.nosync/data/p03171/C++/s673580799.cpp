#include<bits/stdc++.h>
using namespace std;
long long n, a[3005], b[3005];

int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", a+i);
        b[i] = (n%2*2-1)*a[i];
        for(int j = i-1; j >= 0; j--){
            if((n-i+j)&1) b[j] = max(b[j+1] + a[j], b[j] + a[i]);
            else b[j] = min(b[j+1] - a[j], b[j] - a[i]);
        }
    }
    printf("%lld\n", b[0]);
}