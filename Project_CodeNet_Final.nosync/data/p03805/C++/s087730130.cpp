#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    map<pair<int,int>,int> mp;

    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        mp[make_pair(a,b)]++;
        mp[make_pair(b,a)]++;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i]=i;
    }
    int cnt=0;
    while(a[0]==0) {
        bool flag=true;
        for(int i = 1; i < n; i++) {
            if(mp.count(make_pair(a[i-1],a[i]))==0) flag=false;
        }
        if(flag) cnt++;
        next_permutation(a.begin(),a.end());
    }
    cout << cnt << "\n";
    return 0;
}