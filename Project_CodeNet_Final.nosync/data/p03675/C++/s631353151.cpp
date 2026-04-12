#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int b[3*maxn];
int head, tail, n;
bool rev;
int main () {
    scanf ("%d", &n);
    head = maxn+1; tail = maxn;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        if (!rev) {
            b[++tail] = a;
        }
        else {
            b[--head] = a;
        }
        rev = !rev;
    }
    if (!rev) {
        for (int i = head; i <= tail; i++) {
            printf ("%d", b[i]);
            if (i != tail) printf (" ");
            else printf ("\n");
        }
    }
    else {
        for (int i = tail; i >= head; i--) {
            printf ("%d", b[i]);
            if (i != head) printf (" ");
            else printf ("\n");
        }
    }
}
