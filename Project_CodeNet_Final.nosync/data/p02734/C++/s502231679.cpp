#include <bits/stdc++.h>
#define ll long long
#define MAX 3005
#define P 998244353
#define INF 0x3f3f3f3f
using namespace std;

template<typename T>
void read(T &n){
    n = 0;
    T f = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') f = -1, c = getchar();
    while(isdigit(c)) n = n*10+c-'0', c = getchar();
    n *= f;
}
template<typename T>
void write(T n){
    if(n < 0) putchar('-'), n = -n;
    if(n > 9) write(n/10);
    putchar(n%10+'0');
}

int n, m;
int a[MAX];
ll f[MAX][MAX], s[MAX];

void add(ll &a, ll b){
    a += b;
    if(a >= P) a -= P;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = m; j > a[i]; j--){
            add(f[i][j], s[j-a[i]]);
            add(s[j], f[i][j]);
        }
        f[i][a[i]] = i;
        add(s[a[i]], i);
        add(ans, f[i][m]*(n-i+1)%P);
    }
    cout << ans << endl;

    return 0;
}