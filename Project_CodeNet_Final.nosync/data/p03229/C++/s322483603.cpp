#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

int N;

int main(void){
    
    scanf("%d", &N);
    vector<ll> a(N);
    for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);
    
    vector<ll> up, down; up = down = a;
    sort(up.begin(), up.end()), sort(down.begin(), down.end(), greater<ll>());
    
    vector<ll> v1(N, 0), v2(N, 0);
    if(N % 2){
        int cnt = 0, idx = 0;
        for(int i = N / 2; i >= 0 && i < N; i += (cnt % 2) ? cnt * 2 : -(cnt * 2)) ++cnt, v1[i] = up[idx++];
        cnt = 0, idx = 0;
        for(int i = N / 2 - 1; i >= 0 && i < N; i += (cnt % 2) ? cnt * 2 : -(cnt * 2)) ++cnt, v1[i] = down[idx++];
        
        cnt = 0, idx = 0;
        for(int i = N / 2; i >= 0 && i < N; i += (cnt % 2) ? cnt * 2 : -(cnt * 2)) ++cnt, v2[i] = down[idx++];
        cnt = 0, idx = 0;
        for(int i = N / 2 - 1; i >= 0 && i < N; i += (cnt % 2) ? cnt * 2 : -(cnt * 2)) ++cnt, v2[i] = up[idx++];
        
    }
    else{
        int cnt = 0, idx = 0;
        for(int i = N / 2 - 1; i >= 0 && i < N; i += (cnt % 2) ? cnt * 2 : -(cnt * 2)) ++cnt, v1[i] = up[idx++];
        cnt = 0, idx = 0;
        for(int i = N / 2; i >= 0 && i < N; i += (cnt % 2) ? -(cnt * 2) : cnt * 2) ++cnt, v1[i] = down[idx++];
        
        cnt = 0, idx = 0;
        for(int i = N / 2 - 1; i >= 0 && i < N; i += (cnt % 2) ? cnt * 2 : -(cnt * 2)) ++cnt, v2[i] = down[idx++];
        cnt = 0, idx = 0;
        for(int i = N / 2; i >= 0 && i < N; i += (cnt % 2) ? -(cnt * 2) : cnt * 2) ++cnt, v2[i] = up[idx++];
    }
    
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < N - 1; ++i) sum1 += abs(v1[i] - v1[i + 1]), sum2 += abs(v2[i] - v2[i + 1]);
    printf("%lld\n", max(sum1, sum2));
    
    return 0;
}