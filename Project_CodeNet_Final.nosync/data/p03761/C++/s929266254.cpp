#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<string> e;
    string s;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        e.emplace_back(s);
    }
    int cnt=0,tans=1e9;
    vector<int> t;
    for(char i='a';i<='z';i++){
        for(int j=0;j<n;j++) {
            for (int k = 0; k < e[j].size(); k++) {
                if (e[j][k] == i) {
                    cnt++;
                }
            }
            tans = min(tans, cnt);
            cnt = 0;
        }
        t.push_back(tans);
        tans=1e9;
    }
    int cnt2=0;
    for(char i='a';i<='z';i++){
        for(int j=0;j<t[cnt2];j++){
            cout << i;
        }
        cnt2++;
    }
    cout << endl;

    return 0;
}