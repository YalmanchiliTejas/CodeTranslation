#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = (int)1e9 + 7;

int n,m,h[101],hnum[101],dh[101];///h记录每一列高度 dh记录离散化后的各不相同的高度 hnum记录h对应dh中的位置，即第几高的高度
long long dp[101][101];

int pow_(long long x,int y) {///快速幂求 x的y次方
    long long ans = 1;
    if(y > 0) {
        while(y) {
            if(y % 2)ans = ans * x % MOD;
            x = x * x % MOD;
            y /= 2;
        }
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%d",&h[i]);
        dh[++ m] = h[i];///先把高度存到dh数组 下标从1开始，方便后面dp
    }
    sort(dh + 1,dh + m + 1);///dh数组排序
    m = unique(dh + 1,dh + m + 1) - dh - 1;///dh数组离散化去掉重复的高度 m是不相同的高度数
    for(int i = 1;i <= n;i ++) {
        hnum[i] = lower_bound(dh + 1,dh + m + 1,h[i]) - dh;///每一列高度在dh数组中对应的位置
    }
    dp[0][0]=1;///初始化 当第0列有1个无连续相同的方案
    for(int i = 1;i <= n;i ++) {///对每一列每个高度段进行更新 更新过程为从下往上
        (dp[i][0] += dp[i - 1][0] * 2 % MOD) %= MOD;///无连续相同方案  加上前i - 1列无连续相同方案数*2 因为可以是与前一列对应位置同色或者异色一共两种方案
        for(int j = hnum[i] + 1;j <= hnum[i - 1];j ++)///如果前一列比这一列高，高出的部分也存着接触部分无连续相同的方案 但是可能会重复加上上一步的方案数所以下面更新高出的部分时会避免
            (dp[i][0] += dp[i - 1][j] * 2 % MOD) %= MOD;
        int d = pow_(2,h[i] - h[i - 1]);///比前一列高出部分的涂色方案数，如果比前一列低 d就等于1
        for(int j = 1;j <= min(hnum[i - 1],hnum[i]);j ++) {
            dp[i][j] = dp[i - 1][j] * d % MOD;///有连续相同颜色的方案数 已经分析过接触部分的颜色一定是定下的 所以这一列接触部分有连续相同部分的方案数由高出部分的变化决定 即 乘上d
        }
        for(int j = hnum[i - 1] + 1;j <= hnum[i];j ++) {///更新比前一列高出的部分 j从上一列的高度加1的下标开始
            if(j > 1)(dp[i][j] += dp[i - 1][0] * (pow_(2,dh[j] - dh[j - 1]) - 1) % MOD * 2 % MOD * pow_(2,h[i] - dh[j]) % MOD) %= MOD;
            ///一般情况 前i - 1列无连续方案 * （第j块高度变化方案 -1表示去掉重复的 这里会包括一种前面计算过的方案 容易想到) * 剩下几块高度的变化方案数
            else (dp[1][1] += dp[0][0] * (pow_(2,dh[1]) - 2) % MOD * pow_(2,h[i] - dh[1]) % MOD) %= MOD;
            ///第一列的第一块高度 记录随意变化方案数 -2表示除去dp[i][0]已经记录过的 勿重复记录
        }
    }
    long long ans = 0;
    for(int i = 0;i <= hnum[n];i++)
        (ans += dp[n][i]) %= MOD;
    printf("%lld",ans);
    return 0;
}
