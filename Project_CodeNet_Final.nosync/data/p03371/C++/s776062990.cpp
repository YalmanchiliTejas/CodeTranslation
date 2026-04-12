#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;
#define PI 3.14159265359

// 約数の数
int divisor_count(int n)
{
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) ans++;
    }

    return ans;
}

// 公約数
void common_divisor(int a, int b, int *array)
{
    int k = 0;
    for(int i = min(a, b); i >= 1; i--){
        if(a % i == 0 && b % i == 0){
            array[k] = i;
            k++;
        }
    }
}

// 桁数
int digit_count(long long n)
{
    int ans = 0;
    while(1){
        n /= 10;
        ans++;
        if(n == 0) break;
    }

    return ans;
}



int main()
{
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = 1000000000;
    for(int ABpizza = 0; ABpizza <= max(2 * X, 2 * Y); ABpizza += 2){
        int Apizza = X - ABpizza / 2;
        int Bpizza = Y - ABpizza / 2;
      if(Apizza <= 0) Apizza = 0;
      if(Bpizza <= 0) Bpizza = 0;
        ans = min(ans, Apizza * A + Bpizza * B + ABpizza * C);
    }

    cout << ans << endl;

    
    return 0;
}