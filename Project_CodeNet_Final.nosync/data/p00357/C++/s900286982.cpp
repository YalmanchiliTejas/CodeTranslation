#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

int N;

int solve(const vector<int>& d){
    i64 MAX = 0;
    rep(i,0,N - 1){
        if(i * 10 > MAX) return 0;
        MAX = max(MAX , 10LL * i + d[i]);
    }
    return 1;
}

int main(){
    cin >> N;
    vector<int> d(N);
    rep(i,0,N - 1){
        cin >> d[i];
    }
    int res = solve(d);
    reverse(d.begin(),d.end());
    res &= solve(d);

    if(res) cout << "yes" << endl;
    else cout << "no" << endl;
}

