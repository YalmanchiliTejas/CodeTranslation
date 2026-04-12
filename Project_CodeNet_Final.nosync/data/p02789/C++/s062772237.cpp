#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (b>a) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    if(n==m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}


