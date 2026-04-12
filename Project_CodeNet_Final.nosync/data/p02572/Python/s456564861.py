
N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7
s = 0
ans = 0
for i in range(N):
    ans += s * A[i]
    s += A[i]
    ans %= mod
    s %= mod

print (ans)
