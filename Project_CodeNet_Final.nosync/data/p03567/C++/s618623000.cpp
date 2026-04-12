#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size() - 1; i++){
        if (S.at(i) == 'A' && S.at(i + 1) == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}


