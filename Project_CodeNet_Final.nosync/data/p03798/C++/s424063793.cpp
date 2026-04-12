#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n;
string s;
int species[N];

bool good() {
    for (int i = 2; i < n; i++) {
        species[i] = species[i - 2] ^ (s[i - 1] ^ species[i - 1]);
    }
    int firstSpecies = species[n - 2] ^ (s[n - 1] ^ species[n - 1]);
    int lastSpecies = species[1] ^ (s[0] ^ species[0]);
    if (firstSpecies == species[0] && lastSpecies == species[n - 1]) {
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
//     n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') s[i] = 1;
        else s[i] = 0;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            species[0] = i;
            species[1] = j;
            if (good()) {
                for (int i = 0; i < n; i++) {
                    printf(species[i] == 1 ? "S" : "W");
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}