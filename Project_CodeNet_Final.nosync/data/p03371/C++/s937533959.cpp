#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int a, b, c, x, y;
    int ans = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    if (a + b <= 2 * c){
        ans = a * x + b * y;
    } else{
        ans += 2 * c * min(x, y);
        if (x > y){
            if (a > 2 * c){
                ans += 2 * c * (x - y);
            }else{
                ans += a * (x - y);
            }
        }else {
            if (b > 2 * c){
                ans += 2 * c * (y - x);
            }else{
                ans += b * (y - x);
            }
        }
    }
    printf("%d\n", ans);
}