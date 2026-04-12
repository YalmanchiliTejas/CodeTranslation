#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> hen(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        hen[a].push_back(b);
        hen[b].push_back(a);
    }
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    int cnt = 0;
    do {
        if(a.front() != 0)continue;
        bool res = true;
        for(int i = 0; i < n - 1; i++) {
            bool fff = false;
            for(auto j : hen[a[i]])if(j == a[i + 1])fff = true;
            if(!fff)res = false;
        }
        cnt += res;

    }while(next_permutation(a.begin(), a.end()));
    cout << cnt << endl;
}