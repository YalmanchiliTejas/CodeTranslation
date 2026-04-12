#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

vector<ll> a,ret;

bool isOK(int index, int key) {
    /*indexが条件を満たすかどうかを判定(今回はkeyよりおおきいか)*/
    if(ret[index] < key)
        return true;
    else
        return false;
}

int binary_search(int key) {
    int ng = -1;
    int ok = (int)ret.size();
    //okとngの初期値によって最大値だけでなく最小値も求められる.
    //ng=-1の時はkey以上の数値の最小値

    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if(isOK(mid, key))
            ok = mid;
        else
            ng = mid;
    }

    return ok;
}

int main() {
    ll i,n;
    cin >> n;
    a.resize(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }

    ret.resize(n,-1);
    for(i=0;i<n;i++){
        int x = binary_search(a[i]);
        ret[x] = a[i];
    }
    ll cnt = 0;

    for(i=0;i<n;i++){
        if(ret[i]!=-1)cnt++;
        else break;
    }
    cout << cnt << endl;
    return 0;
}