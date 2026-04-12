#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    for (int i = 0; i < N; i++){
        if (S.at(K - 1) == S.at(i)){
            cout << S.at(i);
        }
        else {
            cout << "*";
        }
    }
    cout << endl;
}

