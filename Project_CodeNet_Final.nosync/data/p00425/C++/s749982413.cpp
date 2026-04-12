#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

void north(int &f, int &s, int &u) {
    int t = f;
    f = 7 - u;
    u = t;
}

void east(int &f, int &s, int &u) {
    int t = u;
    u = 7 - s;
    s = t;
}

void west(int &f, int &s, int &u) {
    int t = s;
    s = 7 - u;
    u = t;
}

void south(int &f, int &s, int &u) {
    int t = u;
    u = 7 - f;
    f = t;
}

void right(int &f, int &s, int &u) {
    int t = s;
    s = 7 - f;
    f = t;
}

void left(int &f, int &s, int &u) {
    int t = f;
    f = 7 - s;
    s = t;
}

void solve2(int N) {
    int a[3];
    a[0] = 2; a[1] = 3; a[2] = 1;
    
    int u = 1;
    REP(i, N) {
        string s;
        cin >> s;
        if (s == "North") {north(a[0], a[1], a[2]); u += a[2];}
        if (s == "East") {east(a[0], a[1], a[2]); u += a[2];}
        if (s == "West") {west(a[0], a[1], a[2]); u += a[2];}
        if (s == "South") {south(a[0], a[1], a[2]); u += a[2];}
        if (s == "Right") {right(a[0], a[1], a[2]); u += a[2];}
        if (s == "Left") {left(a[0], a[1], a[2]); u += a[2];}
    }
    cout << u << endl;
}

int main() {
    int N;
    while(cin >> N, N) {
        solve2(N);
    }
    return 0;
}