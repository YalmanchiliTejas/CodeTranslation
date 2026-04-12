#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long n, x;
vector<long long> bp(55);
vector<long long> p(55);

long long f(long long m, long long y) {
    if(m == 0) {
        if(y <= 0) return 0;
        else return 1;
    }else {
        if(y <= 1+bp.at(m-1)) {
            return f(m-1, y-1);
        }else {
            return p.at(m-1)+1+f(m-1, y-bp.at(m-1)-2);
        }
    }
}

int main() {
    bp.at(0) = 1; p.at(0) = 1;
    for(int i = 1; i < 55; i++) {
        bp.at(i) = 2*bp.at(i-1) + 3;
        p.at(i) = 2*p.at(i-1) + 1;
    }
    cin >> n >> x;

    cout << f(n, x) << endl;
}