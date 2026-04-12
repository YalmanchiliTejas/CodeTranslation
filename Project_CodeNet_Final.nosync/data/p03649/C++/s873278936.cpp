#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 50;

ll v[MAXN + 1];



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    bool flag = 1;
    ll ans = 0;
    while(flag) {
        //std::sort(v + 1, v + n + 1, greater<int>());
        if(*max_element(v + 1, v + n + 1) < n)
            flag = 0;
        else {
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++)
                    if(i != j)
                       v[j] += v[i] / n;
                ans += v[i] / n;
                v[i] %= n;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
