#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int N;

int main(void){
    
    scanf("%d", &N);
    printf("%d\n", 800 * N - ((N / 15) * 200));
    
    return 0;
}