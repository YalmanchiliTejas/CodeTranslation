#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int main() {
    int X;
    scanf("%d", &X);
    printf("%s\n", X == 3 || X == 5 || X == 7 ? "YES" : "NO");
    return 0;
}