#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1 << 30;

using namespace std;

using ll = long long;
using P = tuple<int, int>;
using iarr = valarray<int>;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    vector<int> v;
    for(int i = N-1; i >= 0; --i){
        auto itr = upper_bound(v.begin(), v.end(), a[i]);
        if(itr == v.end()){
            v.push_back(a[i]);
        }else{
            *itr = a[i];
        }
    }
    cout << v.size() << endl;
    return 0;
}

