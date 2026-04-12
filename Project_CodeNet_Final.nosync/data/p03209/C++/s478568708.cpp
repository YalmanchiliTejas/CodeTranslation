#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
long long calc_an(int n)  //レベルnの層の総数
{
    if (n > 0){
        return 2 * calc_an(n - 1) + 3;
    }else{
        return 1;
    }
}

long long calc_bn(int n)  //レベルnのパティの総数
{
    if (n > 0){
        return 2 * calc_bn(n - 1) + 1;
    }else{
        return 1;
    }
}

long long f(int n, long long x)
{
    if (n == 0){
        return 1;
    }
    else if (x <= n){
        return 0;
    }
    else if (x == calc_an(n - 1) + 2){
        return calc_bn(n - 1) + 1;
    }
    else if (x > 2 * calc_an(n - 1) + 2){
        return calc_bn(n);
    }

    //下のn-1バーガー
    else if (x <= calc_an(n - 1) + 1){
        return f(n - 1, x - 1);
    } 
    //上のn-1バーガー
    else{
        return f(n - 1, x - calc_an(n - 1) - 2) + calc_bn(n - 1) + 1;
    }
}

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    cout << f(n, x) << endl;
}