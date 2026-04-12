import sys
readline = sys.stdin.readline

N = int(readline().strip())
A = list(map(int, readline().split()))
L = 10**9 + 7

ans = 0
a = A[N-1]
for i in range(N-2, -1, -1):
  ans += A[i]*a
  ans %= L
  a += A[i]

print(ans)