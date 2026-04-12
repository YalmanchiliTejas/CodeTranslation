#include <cstdio>
using namespace std;

int main(){
    int x, y, z, temp;
    scanf("%d%d%d", &x, &y, &z);
    temp = y+z;
    int ans = x / temp;
    if(x - ans*temp < z) ans--;
    printf("%d\n", ans);
    return 0;
}
