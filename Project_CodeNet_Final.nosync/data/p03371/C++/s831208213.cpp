#include <iostream>
int main(){
    long long A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;
    long long ans = 0;
    long long res = 0;
    res = std::max(X, Y)*(2*C);
    if(A + B >= C*2){
        ans += std::min(X, Y)*(2*C);
        ans += A*(X - std::min(X, Y)) + B* (Y - std::min(X,Y));
    }
    else ans += A*X+B*Y;
    std::cout << std::min(ans, res) << std::endl;
}