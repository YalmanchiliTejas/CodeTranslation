#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e5+7, RT = 300;
int a[N];
LL sum[N][RT];

LL query(int l, int r, int d) {
    assert((r-l)%d==0);
    if (d < RT) {
        if (l<=d)    return sum[r][d];
        return sum[r][d] - sum[l-d][d];
    }

    LL ans = 0;
    for (int i=l; i<=r; i+=d)   ans += a[i];
    return ans;
}

vector<int> divs[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=1; i<N; i++)
        for (int j=i; j<N; j+=i)
            divs[j].push_back(i);

    int n;
    cin>>n;
    n--;

    for (int i=0; i<=n; i++)    cin>>a[i];
    for (int i=1; i<RT && i<=n; i++) {
        for (int j=1; j<=n; j++) {
            sum[j][i] = a[j];
            if (j>=i)  sum[j][i] += sum[j-i][i];
        }
    }

    LL ans = 0;
    for (int a=1; a<n; a++) {
        for (int d: divs[n-a]) {
            if (d >= a) break;
            int k = (n-a)/d;
            if (a%d==0 && k*d>=a)   continue;
            LL x = query(a, n, d) ;
            LL y = query(d, k*d, d);
            LL cur =  x + y;
            ans = max(ans, cur);
//            cout<<a<<" "<<a-d<<" = "<<cur<<" "<<x<<" "<<y<<endl;
        }
    }
    cout<<ans<<endl;
}
