#include <bits/stdc++.h>
#include <queue>
#define ll long long int
using namespace std;


const int N = 3e5 + 10;
ll n, m;
bool vis1[200], vis2[200];
string str[200];

void check(ll a) {
    bool ok = true;
    char c = '.';
    for (int j = 0; j < m; j++) {
        if (str[a][j] != c) {
            ok = false;
            break;
        }
    }
    if (ok) vis1[a] = 1;
}

void check1(ll a) {
    bool ok = true;
    char c = '.';
    for (int j = 0; j < n; j++) {
        if (str[j][a] != c) {
            ok = false;
            break;
        }
    }
    if (ok) vis2[a] = 1;
}

int main(int argc, char** argv) {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < n; i++)check(i);
    for (int i = 0; i < m; i++)check1(i);
    for (int i = 0; i < n; i++) {
        if (vis1[i])continue;
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (vis2[j])continue;
            else cout << str[i][j], ok = true;
        }
        if (ok)
            cout << endl;
    }
    return 0;
}