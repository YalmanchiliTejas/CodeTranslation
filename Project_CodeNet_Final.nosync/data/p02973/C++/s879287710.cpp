#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N; cin >> N;
    ll A[100005];
    for (int i = 0;i < N;i++){
        cin >> A[i];
    }

    vector<ll> lis;
    lis.push_back(1);

    for (int i = 0;i < N;i++){
        ll idx = upper_bound(lis.begin(),lis.end(),-A[i]) - lis.begin();
        if(idx >= lis.size()-1){
            if(-A[i] < lis[lis.size()-1])lis[lis.size()-1] = -A[i];
            else lis.push_back(-A[i]);
        }else{
            lis[idx] = -A[i];
        }
    }

    cout << lis.size() << endl;

    return 0;

}