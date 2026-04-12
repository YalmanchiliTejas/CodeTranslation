import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

mod = int(1e9+7)

S = sum(A)

ans = 0
for i in range(N):
  S -= A[i]
  ans += A[i] * S
  ans %= mod

print(ans)