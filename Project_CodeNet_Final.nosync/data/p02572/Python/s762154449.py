N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7

ans = 0
s = A[0]
for i in range(1,N):
    ans += s*A[i]
    ans %= mod
    s += A[i]
    s %= mod
print(ans)