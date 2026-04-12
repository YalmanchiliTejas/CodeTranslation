#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
const long long INF = 1e9;
vector<long long> nowdp(100100, -1);

bool isOK(int index, int key) {
    if(nowdp.at(index) < key) return true;
    else return false;
}

int binary_search(int key) {
    int ng = -1;
    int ok = n+1;

    while(abs(ok-ng) > 1) {
        int mid = (ok+ng) / 2;
        if(isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main() {
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) cin >> a.at(i);

    int now = 0;
    for(int i = 0; i < n; ++i) {
        int check = a.at(i);
        int chno = binary_search(check);
        if(nowdp.at(chno) == -1) now++;
        nowdp.at(chno) = check;
    }
    cout << now << endl;
}