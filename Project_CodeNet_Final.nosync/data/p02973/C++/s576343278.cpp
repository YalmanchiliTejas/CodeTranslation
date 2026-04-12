#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    multiset<int> cnt;
    cnt.insert(vec.at(0));
    for(int i = 1;i < N;i++) {
        auto itr = cnt.lower_bound(vec.at(i));
        if(itr == cnt.begin()) {
            cnt.insert(vec.at(i));
        }
        else {
            --itr;
            itr = cnt.erase(itr);
            cnt.insert(vec.at(i));
        }
    }
    cout << cnt.size() << endl;
}