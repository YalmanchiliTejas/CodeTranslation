import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
from itertools import accumulate

n = int(input())
A = list(map(int, input().split()))
L = [0] + list(accumulate(A))
dp = [[0]*(n+1) for i in range(n+1)]
for d in range(1, n+1):
  for i in range(n+1-d):
    dp[i][i+d] = max(A[i] + L[i+d] - L[i+1] - dp[i+1][i+d], A[i+d-1] + L[i+d-1] - L[i] - dp[i][i+d-1])
ans = 2*dp[0][n] - L[n]
print(ans)