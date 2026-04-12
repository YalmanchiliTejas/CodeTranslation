#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<set>
#include<numeric>
#include<functional>
#include<unordered_map>
using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int target = 100 * r + 10 * g + b;
    if (target % 4 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}