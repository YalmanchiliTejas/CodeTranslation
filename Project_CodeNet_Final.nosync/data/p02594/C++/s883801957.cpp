//
// Created by karth on 8/2/2020.
//
// BDTSL
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define INF 1e18
#define MOD 1e9+7

//void setIO(string s) {
//    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen((s+".in").c_str(),"r",stdin);
//    freopen((s+".out").c_str(),"w",stdout);
//}
int factorial(int n) {
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    if(x>=30){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
    return 0;
}


