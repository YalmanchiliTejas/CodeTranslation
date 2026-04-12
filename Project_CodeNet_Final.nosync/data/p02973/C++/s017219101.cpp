#include <bits/stdc++.h>
using namespace std;
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}

int main()
{
    int N; cin >> N;
    vector<int> A(N); cin >> A;
    vector<int> s;

    for (int a : A) {
        auto it = lower_bound(s.rbegin(), s.rend(), a);
        if (it == s.rbegin()) {
            s.push_back(a);
        } else {
            *(--it) = a;
        }
    }

    cout << s.size() << endl;
}
