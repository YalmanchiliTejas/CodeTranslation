#include <cstdio>
#include <iomanip>    // setw 控制输出间隔函数
#include <iostream>   // cin, cout, abs
#include <algorithm>  // max, min, swap, sort
#include <cmath>      // pow
#include <cstring>    // strlen, memset
#include <set>        // set 集合
#include <stack>      // stack 栈
#include <queue>      // queue 队列
#include <string>     // string 字(yang)符(rou)串, substr
#include <map>
#include <fstream>
using namespace std;
int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    x -= z;
    y += z;
    x /= y;
    printf("%d\n", x);
    return 0;
}
