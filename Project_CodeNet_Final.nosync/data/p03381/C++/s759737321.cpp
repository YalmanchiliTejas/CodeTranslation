#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> x(n);
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> x[i].first, x[i].second = i;
    sort(x.begin(), x.end());
    int k = n/2;
    for (int i=0; i<n; i++) {
        int p;
        if (i < k) p = x[k].first;
        else p = x[k-1].first;
        a[x[i].second] = p;
    }
    for (int i=0; i<n; i++)
        cout << a[i] << endl;
}