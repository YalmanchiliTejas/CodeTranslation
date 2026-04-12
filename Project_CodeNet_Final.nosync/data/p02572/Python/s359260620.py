N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7
cum = [0] * (N-1)
cum[0] = A[0]%mod
for i in range(1,N-1):
    cum[i] = cum[i-1] + A[i]
    cum[i] %= mod
ans = 0
for i in range(1,N):
    ans += cum[i-1]*A[i]
    ans %= mod
print(ans)