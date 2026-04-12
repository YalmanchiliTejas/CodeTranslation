#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[200000][2];
int b[200000][2];

int main() {
    int n, i;
    long long ans = 1e18;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        if (x > y) swap(x, y);
        
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end());
    
    a[0][0] = a[0][1] = v[0].second;
    
    for (i = 1; i < n; i++) {
        a[i][0] = min(a[i - 1][0], v[i].second);
        a[i][1] = max(a[i - 1][1], v[i].second);
    }
    
    b[n - 1][0] = b[n - 1][1] = v[n - 1].second;
    
    for (i = n - 1; i >= 0; i--) {
        b[i][0] = min(b[i + 1][0], v[i].second);
        b[i][1] = max(b[i + 1][1], v[i].second);
    }
    
    for (i = 0; i < n; i++) {
        long long m1, m2, m3, m4;
        
        if (i == n - 1) {
            m1 = v[0].first;
            m2 = v[n - 1].first;
            m3 = a[n - 1][0];
            m4 = a[n - 1][1];
        } else {
            m1 = v[0].first;
            m2 = b[i + 1][1];
            m3 = min(a[i][0], v[i + 1].first);
            m4 = max(a[i][1], v[n - 1].first);
        }
        
        ans = min(ans, (m2 - m1) * (m4 - m3));
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
