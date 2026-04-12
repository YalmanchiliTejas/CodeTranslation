#include <iostream>
using namespace std;

const long MAX = 100000+1;
int v[MAX];
int help[MAX];

bool test(int a, int b, long n) {
        for (long i=1; i<=n; ++i) {
                v[i] = 0;
        }
        v[0] = a;
        v[1] = b;
        for (long i=2; i<n; ++i) {
                v[i] = (!(v[i-1]^help[i-1])) ^ v[i-2];
        }
        int v0 = (!(v[n-1]^help[n-1])) ^ v[n-2];
        int v1 = (!(v[0]^help[0])) ^ v[n-1];
        return ((v0 == v[0]) && (v1==v[1]));
}

int main() {
        long n;
        string s;
        cin >> n >> s;
        for (long i=0; i<n; ++i) {
                if (s[i] == 'o') help[i] = 0;
                else help[i] = 1;
        }
        if (test(1, 1, n)) {
                for (long i=0; i<n; ++i) {
                        printf("%c", v[i]?'S':'W');
                }
                printf("\n");
        } else if (test(1, 0, n)) {
                for (long i=0; i<n; ++i) {
                        printf("%c", v[i]?'S':'W');
                }
                printf("\n");
        } else if (test(0, 1, n)) {
                for (long i=0; i<n; ++i) {
                        printf("%c", v[i]?'S':'W');
                }
                printf("\n");
        } else if (test(0, 0, n)) {
                for (long i=0; i<n; ++i) {
                        printf("%c", v[i]?'S':'W');
                }
                printf("\n");
        } else {
                printf("-1\n");
        }
        return 0;
}
