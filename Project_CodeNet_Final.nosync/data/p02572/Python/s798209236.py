N = int(input())
A = list(map(int, input().split()))
total = sum(A)
mod = 10**9+7

ans = 0
for i in range(N):
    total -= A[i]
    ans = (ans + A[i] * total) % mod

print(ans)