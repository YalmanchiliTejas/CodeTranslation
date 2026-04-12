#include<iostream>

int main(){

    size_t a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    size_t ans = 0;

    while(x != 0 && y != 0){
        if(a + b > c * 2){
            ans += c * 2;
        }else{
            ans += a + b;
        }
        x--, y--;
    }

    if(x == 0){
        if(b > c * 2){
            ans += c * 2 * y;
        }else{
            ans += b * y;
        }
    }else{
        if(a > c * 2){
            ans += c * 2 * x;
        }else{
            ans += a * x;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
