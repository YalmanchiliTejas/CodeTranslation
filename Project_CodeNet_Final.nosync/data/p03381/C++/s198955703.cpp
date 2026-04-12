#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> v;
int a[maxn];
int main(){
   // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        a[i] = t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int f,s;
    f = n/2-1;
    s = f+1;
    for(int i = 0; i < n; i++){
        if(a[i] <= v[f]) cout << v[s] << "\n";
        else cout << v[f] << "\n";
    }
    return 0;
}