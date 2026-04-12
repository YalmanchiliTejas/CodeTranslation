n = int(input())
A = list(map(int, input().split()))
mod = 10**9+7

ans = 0
s = 0
for i in range(n):
    ans += s*A[i]
    ans %= mod
    s += A[i]
    s %= mod
print(ans)
