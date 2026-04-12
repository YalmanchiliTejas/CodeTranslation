#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ans[200000];

int main() {
    int n, i;
    vector <pair<int, int>> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) {
        if (i < n / 2) {
            ans[v[i].second] = v[n / 2].first;
        } else {
            ans[v[i].second] = v[n / 2 - 1].first;
        }
    }
    
    for (i = 0; i < n; i++) printf("%d\n", ans[i]);
    
    return 0;
}
