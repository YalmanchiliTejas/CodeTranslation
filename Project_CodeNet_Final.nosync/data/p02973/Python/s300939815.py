import sys
input = sys.stdin.readline
import bisect

N = int(input())
# 逆順にする
A = [int(input()) for _ in range(N)][::-1]

dp = [float("inf")] * N

# 狭義単調増加列の長さの最大値を求める
for a in A:
    idx = bisect.bisect_right(dp, a)
    dp[idx] = a

answer = bisect.bisect_left(dp, float("inf"))
print(answer)