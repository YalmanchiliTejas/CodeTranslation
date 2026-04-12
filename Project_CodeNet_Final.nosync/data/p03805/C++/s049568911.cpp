
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>

using namespace std;

vector<vector<int>> p;
int n, m;

int ser(int now, int l, vector<bool> ch) {
    if(l == n) {
        return 1;
    }
    int ans = 0;
    for(int i = 0; i < p[now].size(); i++) {
        if(!ch[p[now][i]]) {
            vector<bool> cc = ch;
            cc[p[now][i]] = true;
            ans += ser(p[now][i], l+1, cc);
        }
    }
    return ans;
}

int main() {
    
    cin >> n >> m;
    p.resize(n);
    for(int i = 0; i < m;i++) {
        int t, f;
        cin >> t >> f;
        p[t - 1].push_back(f - 1);
        p[f - 1].push_back(t - 1);
    }
    int ans = 0;
        vector<bool> b;
        b.resize(n);
        b[0] = true;
        ans += ser(0, 1, b);
    cout << ans << endl;
    return 0;
}