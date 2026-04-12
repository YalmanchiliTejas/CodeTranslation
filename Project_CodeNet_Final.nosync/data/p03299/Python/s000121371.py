
"""

https://atcoder.jp/contests/agc026/tasks/agc026_d

10101100011
01010011100

→1列目を決めたとする
→2列目の置き方は、左端を決めればすべて決まる
偶数列目を反転してみる？

10 → 11
01    00

10 → 11
10    11

すなわち、偶数列目が反転して表示されるとすると

全て01を入れ替える or 全てそのまま　しか許されない
→すべてそのままが可能なのは全て0 or 1のときのみ

dp[i][0][X] = i列目の下からX個まですべて0の時の通り数
dp[i][1][X] = i列目の下からX個まですべて1の時の通り数
→答えは dp[i][0][0]

if h[i-1] >= h[i]:
    dp[i][0][X] = dp[i-1][1][X] + dp[i-1][0][h[i]]
    dp[i][1][X] = dp[i-1][0][X] + dp[i-1][1][h[i]]
else:
    if X <= h[i-1]:
        dp[i][0][X] = (dp[i-1][1][X] + dp[i-1][0][h[i-1]]) * pow(2,h[i]-h[i-1],mod)
        dp[i][1][X] = (dp[i-1][0][X] + dp[i-1][1][h[i-1]]) * pow(2,h[i]-h[i-1],mod)
    else:
        dp[i][0][X] = (dp[i-1][1][h[i-1]] + dp[i-1][0][h[i-1]]) * pow(2,h[i]-X,mod)
        dp[i][1][X] = (dp[i-1][0][h[i-1]] + dp[i-1][1][h[i-1]]) * pow(2,h[i]-X,mod)

"""

from sys import stdin

N = int(stdin.readline())
h = list(map(int,stdin.readline().split()))
mod = 10**9+7

dp = [ [{},{}] for i in range(N) ]
numlis = set()
numlis.add(1)
for i in h:
    numlis.add(i)
for i in numlis:
    if i <= h[0]:
        dp[0][0][i] = pow(2,h[0]-i,mod)
        dp[0][1][i] = pow(2,h[0]-i,mod)

for i in range(1,N):

    for X in numlis:
        if X > h[i]:
            continue

        if h[i-1] >= h[i]:
            dp[i][0][X] = (dp[i-1][1][X] + dp[i-1][0][h[i]]) % mod
            dp[i][1][X] = (dp[i-1][0][X] + dp[i-1][1][h[i]]) % mod
        else:
            if X <= h[i-1]:
                dp[i][0][X] = (dp[i-1][1][X] + dp[i-1][0][h[i-1]]) * pow(2,h[i]-h[i-1],mod) % mod
                dp[i][1][X] = (dp[i-1][0][X] + dp[i-1][1][h[i-1]]) * pow(2,h[i]-h[i-1],mod) % mod
            else:
                dp[i][0][X] = (dp[i-1][1][h[i-1]] + dp[i-1][0][h[i-1]]) * pow(2,h[i]-X,mod) % mod
                dp[i][1][X] = (dp[i-1][0][h[i-1]] + dp[i-1][1][h[i-1]]) * pow(2,h[i]-X,mod) % mod

print ((dp[N-1][0][1] + dp[N-1][1][1]) % mod)
