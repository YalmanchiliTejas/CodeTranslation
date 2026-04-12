N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7
s = 0
ans = 0
for i in range(N-1,0,-1):
    s += A[i]
    ans += (s*A[i-1])%mod
    ans %= mod
print(ans)