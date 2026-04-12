#include <bits/stdc++.h>
using namespace std;

bool isOK(int index, int key, const vector<int> &v) {
    if (v.at(index) < key) return true;
    else return false;
}

int binary_search(int key, const vector<int> &v) {
    int ng = -1;
    int ok = (int)v.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key, v)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    vector<int> color;
    for (int i = 0; i < n; i++) {
        int index = binary_search(a.at(i), color);
        
        if (index == (int)color.size()) color.push_back(a.at(i));
        else color.at(index) = a.at(i);
    }

    cout << color.size() << endl;
}   