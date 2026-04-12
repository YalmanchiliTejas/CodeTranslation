import bisect
from collections import deque

n=int(input())
seq= [int(input()) for i in range(n)]

# dp[k]:最適に部分列を繋げた時の集合
dp = deque([seq[0]])

for i in range(1,len(seq)):
    if seq[i] <= dp[0]:
        dp.appendleft(seq[i])

    else:
        dp[bisect.bisect_left(dp, seq[i])-1] = seq[i]

print(len(dp))