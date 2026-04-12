#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> nums(n-1);
    rep(i,n-1) nums[i] = i+1;
    int ans = 0;
    do {
        bool flag = true;
        int fir = 0;
        int sec = nums[0];
        bool firexist = false;
        for(int j : v[fir]) {
            if (j == sec) firexist = true;
        }
        if(!firexist) flag = false;
        rep(i,n-2) {
            int now = nums[i];
            int next = nums[i+1];
            bool exist = false;
            for(int j : v[now]) {
                if (j == next) exist = true;
            }
            if(!exist) flag = false;
        }
        if(flag) ans++;
    } while(next_permutation(nums.begin(),nums.end()));
    cout << ans << endl;
}