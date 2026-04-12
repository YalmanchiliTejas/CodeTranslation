#include <cstdio>
#include <cstring>
using namespace std;

int n;
char *s;

void assign(char **ans, char a0, char a1) {
    char a[n+2];
    a[0] = a0;
    a[1] = a1;
    for (int i = 2; i < n + 2; i++) {
        if ((a[i-1] == 'S') == (s[i-1] == 'o')) {
            a[i] = a[i-2];
        } else {
            if (a[i-2] == 'S') {
                a[i] = 'W';
            } else {
                a[i] = 'S';
            }
        }
    }

    if (a[0] == a[n] && a[1] == a[n+1]) {
        strncpy(*ans, a, n);
    }
    return;
}

int main() {
    scanf("%d", &n);

    s = new char[n+2];
    scanf("%s", s);
    s[n] = s[0];
    s[n+1] = s[1];
    
    char *ans = new char[n];

    char sw[] = "SW";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (*ans == 0) {
                assign(&ans, sw[i], sw[j]);
            }
        }
    }

    if (*ans == 0) { strcpy(ans, "-1"); }

    printf("%s\n", ans);

    return 0;
}