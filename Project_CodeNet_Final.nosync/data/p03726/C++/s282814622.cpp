#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)




int N;
set<int> E[101010], EE[101010];
//-----------------------------------------------------------------
int col[101010];
string sol() {
    queue<int> que;
    
    rep(i, 1, N + 1) if (E[i].size() == 1) que.push(i);
    while (!que.empty()) {
        int i = que.front(); que.pop();
        if (E[i].size() == 0) {
            if (col[i]) break;
            for (int j : EE[i]) if (col[j] == 2) break;
            return "First";
        }
        int j = *E[i].begin();

        if (col[i] == 0) {
            if (col[j] == 1) return "First";
            col[j] = 1;
            col[i] = 2;
        }
        
        E[j].erase(i);
        if (E[j].size() == 1) que.push(j);
    }

    return "Second";
}
//-----------------------------------------------------------------
int main() {
    cin >> N;

    if (N == 1) {
        cout << "First" << endl;
        return 0;
    }

    rep(i, 0, N - 1) {
        int a, b; scanf("%d%d", &a, &b);
        E[a].insert(b);
        E[b].insert(a);
        EE[a].insert(b);
        EE[b].insert(a);
    }

    cout << sol() << endl;
}