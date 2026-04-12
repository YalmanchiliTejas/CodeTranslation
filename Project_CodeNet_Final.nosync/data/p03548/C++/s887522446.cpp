#include<cstdio>

using namespace std;

int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int ans = 0;
    x -= z;
    while(x >= y + z){
        x -= y;
        x -= z;
        ans++;
    }
    printf("%d\n", ans);
}