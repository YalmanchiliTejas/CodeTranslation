#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);

    int n;
    n = 100*r + 10 * g + b;
    if(n % 4 == 0){
        printf("YES\n");
    } else {
        printf("NO\n");
    }


    return 0;
}