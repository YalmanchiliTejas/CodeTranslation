#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

inline int mod_add(int a, int b, int m = MOD) {
    int sum = a + b;
    return sum >= m ? sum - m : sum;
}

const int N_MAX = 10005;
const int D_MAX = 100;

int N, D;
string number;
int dp[N_MAX][D_MAX][2];

int solve(int position, int sum, bool match) {
    if (position >= N)
        return sum == 0 ? 1 : 0;

    int &answer = dp[position][sum][match];

    if (answer >= 0)
        return answer;

    answer = 0;
    int number_digit = number[position] - '0';

    for (int digit = 0; digit <= (match ? number_digit : 9); digit++)
        answer = mod_add(answer, solve(position + 1, (sum + digit) % D, match && digit == number_digit));

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> number >> D;
    N = number.size();
    memset(dp, -1, sizeof(dp));
    printf("%d\n", mod_add(solve(0, 0, true), MOD - 1));
}
