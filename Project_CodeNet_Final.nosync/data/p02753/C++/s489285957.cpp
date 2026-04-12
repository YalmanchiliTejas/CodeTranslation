// Copyright [2020] <unknown>
#include <bits/stdc++.h>
using namespace std;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define dbg(x...) { cerr << "\033[32;1m" << #x << " -> "; err(x); }
void err() { cerr << "\033[39;0m" << endl; }
template<typename T, typename... A>
void err(T a, A... x) { cerr << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

#define sz(x) ((int)x.size())

typedef long long LL;

int t, n;

int main(int argc, char const *argv[]) {
    // code
    char s[10];
    scanf("%s", s);
    int n = strlen(s);
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j) {
            if (s[i] != s[j]) {
                puts("Yes");
                return 0;
            }
        }
    puts("No");
    return 0;
}
