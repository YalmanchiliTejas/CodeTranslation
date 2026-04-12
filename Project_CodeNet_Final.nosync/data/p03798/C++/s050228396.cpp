#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) cout << 'S';
        else cout << 'W';
    }
    cout << endl;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(n, -1);
    int cnt;
    a[0] = 1;  a[1] = 1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'o') {
            if (a[i] == 1) a[i + 1] = a[i - 1];
            else a[i + 1] = 1 - a[i - 1];
        }
        else {
            if (a[i] == 1) a[i + 1] = 1 - a[i - 1];
            else a[i + 1] = a[i - 1];
        }
    }
    cnt = 0;
    if (s[n - 1] == 'o') {
        if (a[n - 1] == 1 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 0 && a[0] == 1 - a[n - 2]) cnt++;
    }
    else {
        if (a[n - 1] == 0 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 1 && a[0] == 1 - a[n - 2]) cnt++;
    }
    if (s[0] == 'o') {
        if (a[0] == 1 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 0 && a[1] == 1 - a[n - 1]) cnt++;
    }
    else {
        if (a[0] == 0 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 1 && a[1] == 1 - a[n - 1]) cnt++;
    }
    if (cnt == 2) {
        print(a); return 0;
    }

    a[0] = 1;  a[1] = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'o') {
            if (a[i] == 1) a[i + 1] = a[i - 1];
            else a[i + 1] = 1 - a[i - 1];
        }
        else {
            if (a[i] == 1) a[i + 1] = 1 - a[i - 1];
            else a[i + 1] = a[i - 1];
        }
    }
    cnt = 0;
    if (s[n - 1] == 'o') {
        if (a[n - 1] == 1 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 0 && a[0] == 1 - a[n - 2]) cnt++;
    }
    else {
        if (a[n - 1] == 0 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 1 && a[0] == 1 - a[n - 2]) cnt++;
    }
    if (s[0] == 'o') {
        if (a[0] == 1 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 0 && a[1] == 1 - a[n - 1]) cnt++;
    }
    else {
        if (a[0] == 0 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 1 && a[1] == 1 - a[n - 1]) cnt++;
    }
    if (cnt == 2) {
        print(a); return 0;
    }

    a[0] = 0;  a[1] = 1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'o') {
            if (a[i] == 1) a[i + 1] = a[i - 1];
            else a[i + 1] = 1 - a[i - 1];
        }
        else {
            if (a[i] == 1) a[i + 1] = 1 - a[i - 1];
            else a[i + 1] = a[i - 1];
        }
    }
    cnt = 0;
    if (s[n - 1] == 'o') {
        if (a[n - 1] == 1 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 0 && a[0] == 1 - a[n - 2]) cnt++;
    }
    else {
        if (a[n - 1] == 0 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 1 && a[0] == 1 - a[n - 2]) cnt++;
    }
    if (s[0] == 'o') {
        if (a[0] == 1 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 0 && a[1] == 1 - a[n - 1]) cnt++;
    }
    else {
        if (a[0] == 0 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 1 && a[1] == 1 - a[n - 1]) cnt++;
    }
    if (cnt == 2) {
        print(a); return 0;
    }

    a[0] = 0;  a[1] = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'o') {
            if (a[i] == 1) a[i + 1] = a[i - 1];
            else a[i + 1] = 1 - a[i - 1];
        }
        else {
            if (a[i] == 1) a[i + 1] = 1 - a[i - 1];
            else a[i + 1] = a[i - 1];
        }
    }
    cnt = 0;
    if (s[n - 1] == 'o') {
        if (a[n - 1] == 1 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 0 && a[0] == 1 - a[n - 2]) cnt++;
    }
    else {
        if (a[n - 1] == 0 && a[0] == a[n - 2]) cnt++;
        else if (a[n - 1] == 1 && a[0] == 1 - a[n - 2]) cnt++;
    }
    if (s[0] == 'o') {
        if (a[0] == 1 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 0 && a[1] == 1 - a[n - 1]) cnt++;
    }
    else {
        if (a[0] == 0 && a[1] == a[n - 1]) cnt++;
        else if (a[0] == 1 && a[1] == 1 - a[n - 1]) cnt++;
    }
    if (cnt == 2) {
        print(a); return 0;
    }

    cout << -1 << endl;


    
}
