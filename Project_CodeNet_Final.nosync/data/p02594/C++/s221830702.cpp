#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define reps(i, s, n) for(int i = (int)s; i < (int)n; i++)
#define in(i) std::cin >> i;
#define print(i) std::cout << i;
#define println(i) std::cout << i << std::endl;

int main() {
    int x;
    in(x)
    if(x >= 30)print("Yes")
    else print("No")
    return 0;
}