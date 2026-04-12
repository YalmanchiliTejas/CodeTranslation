#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

int A, B, C, X, Y;

int main(void){
    
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    
    int ans = 0;
    int num = min(X, Y);
    
    ans = (A * num + B * num < C * 2 * num) ? A * num + B * num : C * 2 * num;
    
    if(X == Y) printf("%d\n", ans);
    else{
        if(X > Y){
            num = X - Y;
            ans += (A * num < C * 2 * num) ? A * num : C * 2 * num;
        }
        else{
            num = Y - X;
            ans += (B * num < C * 2 * num) ? B * num : C * 2 * num;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}