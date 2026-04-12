#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<P> x(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x.begin(), x.end());
    for(int i=0;i<n;i++){
        int b = (i<n/2 ? x[n/2].first : x[n/2-1].first);
        ans[x[i].second] = b;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
