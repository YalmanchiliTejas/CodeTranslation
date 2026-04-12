#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
bool b[N];
char s[N];
///sheep - 1, wolf - 0

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    for (int k = 0; k < 8; ++k) {

        for (int j = 0; j < 3; ++j) {
            if ((k >> j) & 1) b[j] = 1;
            else b[j] = 0;
        }

        if (b[1] == 1) { // it's a sheep
            if (s[1] == 'o' and b[0] != b[2]) continue;
            if (s[1] == 'x' and b[0] == b[2]) continue;
        } else { // wolf
            if (s[1] == 'o' and b[0] == b[2]) continue;
            if (s[1] == 'x' and b[0] != b[2]) continue;
        }

        for(int i = 2; i < n; ++i) {
            if(b[i]) {
                if(s[i] == 'o') b[i + 1] = b[i - 1];
                else b[i + 1] = b[i - 1] ^ 1;
            } else {
                if(s[i] == 'o') b[i + 1] = b[i - 1] ^ 1;
                else b[i + 1] = b[i - 1];
            }
        }
        if(b[n] != b[0]) continue;

        if (b[0] == 1) {
            if (s[0] == 'o' and b[1] != b[n - 1]) continue;
            if (s[0] == 'x' and b[1] == b[n - 1]) continue;
        } else {
            if (s[0] == 'o' and b[1] == b[n - 1]) continue;
            if (s[0] == 'x' and b[1] != b[n - 1]) continue;
        }
 
        for(int i = 0; i < n; ++i) putchar(b[i]? 'S' : 'W');
        return 0;
    }
    puts("-1");
}