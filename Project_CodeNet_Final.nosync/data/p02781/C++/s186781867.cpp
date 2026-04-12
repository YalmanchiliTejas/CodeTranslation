#include<algorithm>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<iomanip>
using namespace std;

long long solve(string N, int K) {
    vector<long long> dp = vector<long long>(5, 0);
    vector<long long> topdp = vector<long long>(5, 0);
    dp[0] = 1;
    dp[1] = N[0] - '1';
    topdp[1] = 1;
    bool moveTop = false;
    for (int i = 1; i < N.size(); i++) {
        int x = N[i] - '0';
        for (int j = 3; j >= 1 ; j--) {
            if (x > 0) {
                dp[j] = dp[j-1] * 9 + dp[j] + topdp[j-1] * (x-1) + topdp[j];
            } else {
                dp[j] = dp[j-1] * 9 + dp[j];
            }
        }
        if (x > 0) {
            for (int j = 4; j >= 1 ; j--) {
                topdp[j] = topdp[j-1];
            }
        }
//        cout << topdp[1];
    }
    return dp[K] + topdp[K];
}

long long test(int N, int K) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int num = 0;
        int j = i;
        while (j > 0) {
            if (j % 10 > 0) {
                num++;
            }
            j /= 10;
        }
        if (num == K) {
            sum++;
        }
    }
    return sum;
}

int main()
{
    std::cout<<std::fixed<<std::setprecision(10);
    
    string N;
    int K;
    cin >> N >> K;
    
    cout << solve(N, K);
//    cout << test(stoi(N), K);
    
    
    return 0;
}

struct M {
    long long X;
    long long H;

    bool operator<(const M &another) const
    {
        return X < another.X;
    };
};