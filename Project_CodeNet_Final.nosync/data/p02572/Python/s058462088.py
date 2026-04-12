N = int(input())
A = tuple(map(int,input().split()))
mod = 10**9+7
ans = 0
s = (sum(A) - A[0])%mod
for i in range(N-1):
    if s < 0:
        s += mod
    ans += A[i]*s%mod
    ans %= mod
    s -= A[i+1]
print(ans)