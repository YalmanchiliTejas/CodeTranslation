#include<bits/stdc++.h>
using namespace std;

int main(){
    uint_fast32_t N;
    scanf("%u", &N);

    vector<int_fast64_t> a(N);
    vector<vector<int_fast64_t>> ans(N, vector<int_fast64_t>(N));
    for(auto& i : a)scanf("%lld", &i);

    for(auto i = 0; i < N; ++i)
        ans[i][i] = a[i] * (N & 1 ? 1 : -1);


    for(auto i = 1; i < N; ++i)
        for(auto j = 0; i + j < N; ++j)
            ans[j][i + j] = (i ^ N) & 1 ? max(ans[j][i + j - 1] + a[i + j], ans[j + 1][i + j] + a[j]) : min(ans[j][i + j - 1] - a[i + j], ans[j + 1][i + j] - a[j]);

    cout << ans[0][N - 1] << endl;

    return 0;
}