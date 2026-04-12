#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<long long> rev_s(n);
    rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    vector<vector<long long>> ans(n, vector<long long>(1, 0));

    for (int i = 1; i < n; i++){
        for (int j = i; j < n; j += i){
            if ((n-1) % i == 0 && j > ((n - 2) / 2)) break;
            if (j >= n - i - 1) break;
            ans[i].push_back(ans[i].back() + s[j] + rev_s[j]);
        }
    }
    long long a = 0;
    for (int i = 0; i < n; i++){
        int k = (int)ans[i].size();
        for (int j = 0; j < k; j++){
            a = max(a, ans[i][j]);
        }
    }

    cout << a << endl;

}
