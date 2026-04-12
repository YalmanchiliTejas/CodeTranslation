#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)

ll bin(vector<ll> &vec, ll s, ll e, ll v) {
    if (e - s > 1) {
        ll mid = ((s + e) / 2);
        if (vec[mid] >= v) {
            return bin(vec, mid, e, v);
        } else {
            return bin(vec, s, mid, v);
        }
    } else {
        return e;
    }
}

int main(int argc, const char * argv[]) {
    
    ll N;
    cin >> N;
    vector<ll> maximums = vector<ll>();
    ll count = 0;
    
    for (ll i = 0; i < N; i++) {
        ll data;
        cin >> data;
        if (count == 0 || maximums[count-1] >= data) {
            maximums.push_back(data);
            count++;
            continue;
        } else if (maximums[0] < data) {
            maximums[0] = data;
            continue;
        }
        
        ll index = bin(maximums, 0, count - 1, data);
        maximums[index] = data;

    }
    
    cout << count;
    
    return 0;
}
