#include <bits/stdc++.h>
using namespace std;
bool valid(string s, string t, int n, int N) {
    if (s[n] == 'o') {
        if (t[n] == 'S') {
            return t[(n+1+N)%N] == t[(N+n-1)%N];
        } else {
            return t[(n+1+N)%N] != t[(N+n-1)%N];
        }
    } else {
        if (t[n] == 'S') {
            return t[(n+1+N)%N] != t[(N+n-1)%N];
        } else {
            return t[(n+1+N)%N] == t[(N+n-1)%N];
        }
    }
}
int main() {
    int N;
    string s, t;
    cin >> N >> s;
    t = "SS";
    for (int i = 1; i < N-1; i++) {
        if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('W');
        } else if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('W');
        } else if (t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'S' && s[i] == 'o') {
            t.push_back('W');
        } else if (t[i] == 'W' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'W' && s[i] == 'o') {
            t.push_back('S');
        } else {
            t.push_back('W');
        }
    }
    if (valid(s,t,0,N) && valid(s,t,N-1,N)) {
        cout << t;
        return 0;
    }
    t = "SW";
    for (int i = 1; i < N-1; i++) {
        if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('W');
        } else if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('W');
        } else if (t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'S' && s[i] == 'o') {
            t.push_back('W');
        } else if (t[i] == 'W' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'W' && s[i] == 'o') {
            t.push_back('S');
        } else {
            t.push_back('W');
        }
    }
    if (valid(s,t,0,N) && valid(s,t,N-1,N)) {
        cout << t;
        return 0;
    }
    t = "WS";
    for (int i = 1; i < N-1; i++) {
        if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('W');
        } else if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('W');
        } else if (t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'S' && s[i] == 'o') {
            t.push_back('W');
        } else if (t[i] == 'W' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'W' && s[i] == 'o') {
            t.push_back('S');
        } else {
            t.push_back('W');
        }
    }
    if (valid(s,t,0,N) && valid(s,t,N-1,N)) {
        cout << t;
        return 0;
    }
    t = "WW";
    for (int i = 1; i < N-1; i++) {
        if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'S' && t[i-1] == 'S') {
            t.push_back('W');
        } else if (s[i] == 'o' && t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('W');
        } else if (t[i] == 'S' && t[i-1] == 'W') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'S' && s[i] == 'o') {
            t.push_back('W');
        } else if (t[i] == 'W' && t[i-1] == 'S') {
            t.push_back('S');
        } else if (t[i] == 'W' && t[i-1] == 'W' && s[i] == 'o') {
            t.push_back('S');
        } else {
            t.push_back('W');
        }
    }
    if (valid(s,t,0,N) && valid(s,t,N-1,N)) {
        cout << t;
        return 0;
    }
    cout << -1;
}