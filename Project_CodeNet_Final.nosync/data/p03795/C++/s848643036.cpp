#include <cstdio>
using namespace std;

int main () {
    int N;
    scanf("%d", &N);
    int x = N*800;
    int y = (N/15)*200;
    printf("%d\n", x-y);
}
