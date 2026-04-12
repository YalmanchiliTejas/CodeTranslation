#include<bits/stdc++.h>
using namespace std;

string S;

int main() {
    cin >> S;

    for(int i = 0; i < (int)S.size() - 1; i++) {
        if(S[i] == 'A' && S[i + 1] == 'C') {
            cout << "Yes";
            return 0;
        }
    }

    printf("No");
}
