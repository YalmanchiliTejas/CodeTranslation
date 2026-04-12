#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>

int main(void){
    int A, B, C, X, Y;
    long long int res = 0;
    std::cin >> A >> B >> C >> X >> Y;

    int m = std::min(X, Y);
    if(A + B <= C * 2) res += (A + B) * m;
    else res += C * 2 * m;

    if(X - m > 0) {
        if (A <= C * 2) res += (X - m) * A;
        else res += (X - m) * (C * 2);
    }
    if(Y - m > 0){
        if(B <= C * 2) res += (Y - m) * B;
        else res += (Y - m) * (C * 2);
    }

    std::cout << res << std::endl;

    return 0;
}