#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

bool hasElement(const vector<int>& vec, int target) {
    auto itr = find(vec.begin(), vec.end(), target);
    size_t index = distance( vec.begin(), itr );
    if (index != vec.size()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, m; cin >> n >> m;
    map<int, vector<int> > mp;
    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    vector<int> v(n - 1);
    iota(v.begin(), v.end(), 1);

    int ans = 0;
    do {
        vector<int> root(1);
        root[0] = 0;
        copy(v.begin(),v.end(),std::back_inserter(root));

        bool ret = true;
        for(int i = 0; i < n - 1; ++i){
            if( !hasElement(mp[root[i]], root[i + 1]) ){
                ret = false;
                break;
            }
        }
        if(ret){
            ++ans;
        }


    } while( next_permutation(v.begin(), v.end()) );

    cout << ans << endl;

    return 0;
}

