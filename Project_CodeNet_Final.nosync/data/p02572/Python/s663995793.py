import sys
input = sys.stdin.buffer.readline
from itertools import accumulate

MOD = 10**9 + 7

N = int(input())
A = [0] + list(map(int, input().split()))
C = list(accumulate(A))

ans = 0
for i in range(1, N):
    ans += A[i] * (C[-1] - C[i])

ans %= MOD
print(ans)
