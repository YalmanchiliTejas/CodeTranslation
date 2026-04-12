#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const ll mod = 1e9 + 7;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> x(N);
    vector<int> ans(N);
    for(int i = 0; i < N; ++i) {
        int tmp;
        cin>>tmp;
        x[i]={tmp,i};
    }

    sort(x.begin(),x.end());

    for (int j = 0; j < N; ++j) {
        if(j<N/2) ans[x[j].second]=x[N/2].first;
        else ans[x[j].second]=x[N/2-1].first;
    }

    for (int j = 0; j < N; ++j) {
        cout<<ans[j]<<endl;
    }
    return 0;
}
