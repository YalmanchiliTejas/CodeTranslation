#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

int X, Y, Z;

int main(void){
    
    scanf("%d %d %d", &X, &Y, &Z);
    
    int ans = 0;
    for(int i = Y + Z + Z; i <= X; i += Y + Z) ++ans;
    printf("%d\n", ans);
    
    return 0;
}

