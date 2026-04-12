#include <bits/stdc++.h>

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int X;
    cin >> X;
    if(X >= 30) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}
