#include <cstdio>
#include <cstring>
using namespace std;

int n;
bool *isO;

void assign(char **ans, char a0, char a1) {
    char a[n+2];
    a[0] = a0;
    a[1] = a1;
    for (int i = 2; i < n + 2; i++) {
        if ((a[i-1] == 'S') == isO[i-1]) {
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

    char s[n];
    scanf("%s", s);
    
    char *ans = new char[n];

    isO = new bool[n+2];
    for (int i = 0; i < n; i++) {
        isO[i] = (s[i] == 'o');
    }
    isO[n] = isO[0];
    isO[n+1] = isO[1];

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