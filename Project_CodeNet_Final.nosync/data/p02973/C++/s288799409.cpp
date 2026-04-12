#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 1000000007;
constexpr int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;

using Graph = vector<vector<int>>;


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

	int N;
    cin >> N;
    int A[N];
    rep(i,N) cin >> A[i];
    multiset<int> set1;
    rep(i,N){
        auto itr = set1.lower_bound(A[i]);
        if(itr != set1.begin()) set1.erase(--itr);
        set1.insert(A[i]);
    }
    cout << set1.size() << endl;
}