#include <bits/stdc++.h>
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)


int main(){

    int X, Y, Z; std::cin >> X >> Y >> Z; X -= 2 * Z;

    int ans = (X - Y) / (Y + Z) + 1;

    std::cout << ans;

    system("pause");

    return 0;
}