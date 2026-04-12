#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, D;

long power(long base, long exponent){
    if(exponent % 2){
        return power(base, exponent - 1) * base % long(1e9 + 7);
    }else if(exponent){
        long root_num = power(base, exponent / 2);
        return root_num * root_num % long(1e9 + 7);
    }else{
        return 1;
    }
}

long factorial_surplus[10000];

long combination(int n, int r){
    return factorial_surplus[n] * power(factorial_surplus[r] * factorial_surplus[n - r] % long(1e9 + 7), 1e9 + 5) % long(1e9 + 7);
}

long dp[1001][1001];

long make_group(int member, int remaining){
    if(!remaining){
        return 1;
    }else if(member == B + 1){
        return 0;
    }else if(dp[member - A][remaining - 1] != -1){
        return dp[member - A][remaining - 1];
    }else{
        long ans = make_group(member + 1, remaining);
        long combination_num = 1;
        for(int i = 1; i < C && remaining >= member * i; i++){
            combination_num *= combination(remaining - member * (i - 1), member);
            combination_num %= long(1e9 + 7);
            combination_num *= power(i, long(1e9 + 5));
            combination_num %= long(1e9 + 7);
        }
        for(int i = C; i <= D && remaining >= member * i; i++){
            combination_num *= combination(remaining - member * (i - 1), member);
            combination_num %= long(1e9 + 7);
            combination_num *= power(i, long(1e9 + 5));
            combination_num %= long(1e9 + 7);
            ans += make_group(member + 1, remaining - member * i) * combination_num;
            ans %= long(1e9 + 7);
        }
        return dp[member - A][remaining - 1] = ans;
    }
}

int main(){
    int N;
    cin >> N >> A >> B >> C >> D;
    long times_num = 1;
    for(long i = 0; i < 10000; i++){
        factorial_surplus[i] = times_num;
        times_num *= i + 1;
        times_num %= long(1e9 + 7);
    }
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            dp[i][j] = -1;
        }
    }
    cout << make_group(A, N) << endl;
}
