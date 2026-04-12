#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define print(n) std::cout << n << std::endl
#define FOR(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int r,g,b;
    cin >> r >> g >> b;
    int n = 100 * r + 10 * g + b;
    if(n % 4 == 0)print("YES");
    else print("NO");
 }