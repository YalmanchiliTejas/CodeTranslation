N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7
s = sum(A) % mod
ans = 0
for i in range(N):
    s -= A[i]
    if 0 > s:
        s += mod
    ans += A[i] * s
    ans %= mod
print(ans)