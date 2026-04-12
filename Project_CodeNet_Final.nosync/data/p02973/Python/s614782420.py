from bisect import bisect_right
N = int(input())
A = [int(input()) for i in range(N)]
A = [-a for a in A]

# dp[i] := 長さiの広義単調増加部分列を取る時の最大の数
dp = []
for a in A:
    i = bisect_right(dp, a)
    if i >= len(dp):
        dp.append(a)
    else:
        dp[i] = a

print(len(dp))
