#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a);i <= (b); i++)
#define ROF(i, a, b) for(int i = (a);i >= (b); i--)
const int N = 3e3 + 11;
const int mod = 998244353;
int f[N], a[N];
int n, s;
void Add(int &x, int y){
    x = (x + y) - (x + y >= mod ? mod : 0);
}
int M(int x, int y){
    return 1LL * x * y % mod;
}
int main(){
    cin>>n>>s;
    FOR(i, 1, n)scanf("%d", &a[i]);
    f[0] = 1;
    int ans = 0;
    FOR(i, 1, n){
        if(a[i] > s)continue;
        if(a[i] == s){
            Add(ans, M(n - i + 1, i));
        }
        else Add(ans, M(f[s-a[i]], n - i + 1));
        ROF(j, s - a[i], 1){
            Add(f[j+a[i]], f[j]);
        }
        Add(f[a[i]], M(f[0], i));
    }
    cout<<ans<<endl;
    return 0;
}
