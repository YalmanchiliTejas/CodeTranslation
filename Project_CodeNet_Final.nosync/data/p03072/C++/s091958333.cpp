#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define llong long long
#define INF (__INT32_MAX__ / 2)

using namespace std;

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    int res = 0;
    int highest = -INF;
    for(int i = 0; i < n; ++i) {
        int h;
        scanf("%d", &h);
        if(h >= highest) ++res;
        highest = max(highest, h);
    }

    printf("%d\n", res);
}