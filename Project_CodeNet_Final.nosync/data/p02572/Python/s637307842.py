import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))

# N -> 1の累積和
acum = [0 for _ in range(N+1)]
acum[0] = sum(A)
for i in range(N):
    acum[i+1] = acum[i] - A[i]

mod = 10**9 + 7
ans = 0
for i in range(N):
    ans += acum[i+1] * A[i]
    ans %= mod

print(ans)