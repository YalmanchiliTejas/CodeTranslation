import sys

input = sys.stdin.readline
import bisect

INF = 10 ** 18
N = int(input())
A = [10 ** 10 - int(input()) for _ in range(N)]  # 逆順にしておく

# 最長単調減少列：狭義

dp = [INF] * (N + 1)  # 長さ、その長さの末端としてありうる最大値

for a in A:
    idx = bisect.bisect_right(dp, a)
    dp[idx] = a

answer = bisect.bisect_left(dp, INF)
print(answer)