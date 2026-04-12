#include <bits/stdc++.h>
#define BPhuong "main"
#define maxn 3006
#define maxm
#define fi(i,a,b) for(int i = a; i<= b; i++)
#define fid(i,a,b) for(int i = a; i>= b; i--)
#define se second
#define f first
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define bit(x, i) ((x>>i)&1)
#define oo 1e9
struct data{
    int x, y, z;
};
using namespace std;
int n, a[maxn], cl[maxn][maxn];
long long t[maxn][maxn], s[maxn];
ll tinh(int d, int c)
{
    if(d == c)
    {
        return a[d];
    }
    if(cl[d][c]) return t[d][c];
    cl[d][c] = 1;
    t[d][c] = s[c]-s[d-1]- min(tinh(d+1, c), tinh(d, c-1));
    return t[d][c];
}
void nhap(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    //freopen(BPhuong".inp","r",stdin);
    //freopen(BPhuong".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) s[i] = s[i-1]+a[i];
}

void xuli(){
    long long s1 = tinh(1, n);
    ll s2 = s[n]-s1;
    cout << s1-s2;
}

int main(){
    nhap();
    xuli();
}
