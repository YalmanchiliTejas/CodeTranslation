#include <stdio.h>

int main(){
    int x, y, z, temp;
    scanf("%d%d%d", &x, &y, &z);
    temp = y+z;
    int ans = x / temp;
    // 如果最后的间隙少于z 那么最后一个位置不能座
    if(x - ans*temp < z) ans--;
    printf("%d\n", ans);
    return 0;
}
