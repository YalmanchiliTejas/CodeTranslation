#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sub(n,-1);
    rep(i,n){
        cin >> a[i];
        decltype(sub)::iterator temp = lower_bound(sub.begin(),sub.end(),a[i]);
        int idx;
        idx = distance(sub.begin(),temp);
        if (idx>=n) sub[n-1]=a[i];
        else sub[idx-1]=a[i];
        //cout << a[i] << endl;
        //for(auto s:sub) cout << s << " ";
    }

    int res = 0;
    for(auto s:sub) if(s>=0) res++;

    cout << res << endl;


}