#include<bits/stdc++.h>

long long rec(int n,long long x){ //レベルがnのバーガーに含まれるパティｘ

    if(n == 0)return 1;
    //前のレベルの量
    long long len = (1LL << (n + 1)) - 3;
    long long num = (1LL << n) - 1;
    if(x == 1)return 0;
    else if (x <= len + 1)return rec(n - 1, x - 1);
    else if (x == len + 2)return num + 1;
    else if (x <= (len + 1) * 2)return num + 1 + rec(n - 1, x - len - 2);
    else return num * 2 + 1;
}

int main()
{
    int n; long long x;
    std::cin >> n >> x;
    std::cout << rec(n, x) << std::endl;

}