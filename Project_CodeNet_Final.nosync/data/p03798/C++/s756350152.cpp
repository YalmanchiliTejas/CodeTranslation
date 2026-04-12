#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    //trueがひつじ、falseがおおかみ
    vector<bool> ss(n, true);
    for (int i = 0; i < n; i++){
        if (ss[i] && s[i] == 'o') ss[(i + 1) % n] = ss[(n + i - 1) % n];
        if (ss[i] && s[i] == 'x') ss[(i + 1) % n] = !ss[(n + i - 1) % n];
        if (!ss[i] && s[i] == 'o') ss[(i + 1) % n] = !ss[(n + i - 1) % n];
        if (!ss[i] && s[i] == 'x') ss[(i + 1) % n] = ss[(n + i - 1) % n];
    }
    if (ss.front() && ss.back()){
        for (int i = 0; i < n; i++){
            if (ss[i]) cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }
    vector<bool> ww(n, false);
    for (int i = 0; i < n; i++){
        if (ww[i] && s[i] == 'o') ww[(i + 1) % n] = ww[(n + i - 1) % n];
        if (ww[i] && s[i] == 'x') ww[(i + 1) % n] = !ww[(n + i - 1) % n];
        if (!ww[i] && s[i] == 'o') ww[(i + 1) % n] = !ww[(n + i - 1) % n];
        if (!ww[i] && s[i] == 'x') ww[(i + 1) % n] = ww[(n + i - 1) % n];
    }
    if (!ww.front() && !ww.back()){
        for (int i = 0; i < n; i++){
            if (ww[i]) cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }
    vector<bool> ws(n, false); ws[0] = true;
    for (int i = 0; i < n; i++){
        if (ws[i] && s[i] == 'o') ws[(i + 1) % n] = ws[(n + i - 1) % n];
        if (ws[i] && s[i] == 'x') ws[(i + 1) % n] = !ws[(n + i - 1) % n];
        if (!ws[i] && s[i] == 'o') ws[(i + 1) % n] = !ws[(n + i - 1) % n];
        if (!ws[i] && s[i] == 'x') ws[(i + 1) % n] = ws[(n + i - 1) % n];
    }
    if (ws.front() && !ws.back()){
        for (int i = 0; i < n; i++){
            if (ws[i]) cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }
    vector<bool> sw(n, true); sw[0] = false;
    for (int i = 0; i < n; i++){
        if (sw[i] && s[i] == 'o') sw[(i + 1) % n] = sw[(n + i - 1) % n];
        if (sw[i] && s[i] == 'x') sw[(i + 1) % n] = !sw[(n + i - 1) % n];
        if (!sw[i] && s[i] == 'o') sw[(i + 1) % n] = !sw[(n + i - 1) % n];
        if (!sw[i] && s[i] == 'x') sw[(i + 1) % n] = sw[(n + i - 1) % n];
    }
    if (!sw.front() && sw.back()){
        for (int i = 0; i < n; i++){
            if (sw[i]) cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }
    cout << - 1 << endl;
}