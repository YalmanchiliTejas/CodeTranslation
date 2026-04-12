#include <bits/stdc++.h>

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

vector<int> C;
template<typename T>
void query_first_left_element_greater_than_itself(const vector<T>& A, vector<int>& B) {
    int n = A.size();
    B.resize(n);
    C.clear();
    for (int i = 0; i < n; i++) {
        while (!C.empty() && A[C.back()] <= A[i])
            C.pop_back();
        if (C.empty())
            B[i] = -1;
        else
            B[i] = C.back();
       C.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    vector<int> A, B;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    query_first_left_element_greater_than_itself(A, B);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (B[i] == -1) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
