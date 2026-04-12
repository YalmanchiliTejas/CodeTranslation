#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K;
ll comb[1000][1000], H[1000][1000];
vector<int> sol;

int main() {
    cin >> K;

    for(int i = 0; i < 1000; i++) {
        comb[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000 - i; j++) {
            H[i][j] = comb[i + j - 1][j];
        }
    }

    for(int i = 500; i >= 1; i--) {
        while(K >= H[8][i - 1]) {
            sol.push_back(i);
            K -= H[8][i - 1];
        }
    }

    int pos = (int)sol.size() - 1;
    for(int i = 1; i <= 500; i++) {
        printf("FESTIVA");

        while(pos >= 0 && sol[pos] == i) {
            printf("L");
            pos--;
        }
    }
}
