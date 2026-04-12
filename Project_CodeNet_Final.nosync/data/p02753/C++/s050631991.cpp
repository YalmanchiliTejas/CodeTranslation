#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    for(int i = 0; i < 2; i++) {
        if(S[i] != S[i + 1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }    

    cout << "No" << endl;
}