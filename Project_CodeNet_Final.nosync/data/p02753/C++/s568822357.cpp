#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[4];
    scanf("%s", s);
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++)
        if (s[i] == 'A')
            a = 1;
        else
            b = 1;

    printf(a && b ? "Yes\n" : "No\n");

    return 0;
}
