#include <bits/stdc++.h>

#define reint register int
#define coint const int

using namespace std;

coint SIZE = 100000 + 5;

multiset<int, greater<int> > st;
int li[SIZE];

inline int getint(void) {
    reint x = 0, ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9';
        x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar());
    return x;
}

int main(void) {
    coint n = getint();
    for (reint i = 1; i <= n; ++i) li[i] = getint();
    for (reint i = 1; i <= n; ++i) {
        multiset<int>::iterator it = st.upper_bound(li[i]);
        if (it == st.end()) { st.insert(li[i]); continue; }
        st.erase(it), st.insert(li[i]);
    }
    printf("%d\n", (int)st.size());

    return 0;
}

