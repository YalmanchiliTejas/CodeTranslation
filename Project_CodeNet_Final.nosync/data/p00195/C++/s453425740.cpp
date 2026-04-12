#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    vector<int> vec(5);

    int i = 0;
     int maxv = 0, maxi = 0;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        if (maxv < a+b) {
            maxv = a + b;
            maxi = i;
        }
        
        if (i >= 4) {
            printf("%c %d\n", 'A'+maxi, maxv);
            maxv = 0;
            maxi = 0;
            i = 0;
        }
        else {
            i++;
        }
    }
}
