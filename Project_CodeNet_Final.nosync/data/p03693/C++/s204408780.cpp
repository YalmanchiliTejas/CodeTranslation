#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define SORTR(v,n) sort(v, v+n, greater<int>());
// #define int long long    // %d=>%lld
#define pb push_back
#define INF 100000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;
typedef pair<ll, pll> plll;

int r;
int g;
int b;




signed main(){
    scanf("%d", &r);
    scanf("%d", &g);
    scanf("%d", &b);


    if((g*10+b)%4 == 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }


    return 0;
}