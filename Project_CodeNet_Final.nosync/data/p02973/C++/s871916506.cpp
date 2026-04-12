#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const long long INF = 1LL<<60;

ll N, ans=1, tmp=0, flag=0;
vector<ll> a, vemp(1,INF), PQ(100005,INF);
//vector<pair<ll,ll>> PQ;

// 最長増加部分列の長さを求める
void LIS() {
    while(!a.empty()) {
        ll num = a.back();
        a.pop_back();
        ll id = upper_bound(PQ.begin(), PQ.end(), num)-PQ.begin();
        PQ[id] = num;
    }
    for(int i=0;i<100005;i++) {
        if(PQ[i]==INF) {
            ans = i;
            break;
        }
    }
}    

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll in1;
        cin >> in1;
        a.push_back(in1);
    }
    LIS();
    cout << ans << endl;
    return 0;
}