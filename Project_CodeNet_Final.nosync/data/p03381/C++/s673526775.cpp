#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+1;

int ans[N];
pair <int, int> a[N];
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++ i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    for (int i = 0; i < n; ++ i){
        int m = n/2-1;
        if (i <= m) ++ m;
        ans[a[i].second] = a[m].first;
    }
    for (int i = 0; i < n; ++ i)
        cout << ans[i] << endl;
}
