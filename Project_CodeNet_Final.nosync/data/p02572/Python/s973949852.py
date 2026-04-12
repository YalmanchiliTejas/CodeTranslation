n = int(input())
A = list(map(int, input().split()))
mod = 10**9+7

acc = [0]
for a in A:
    acc.append((acc[-1]+a)%mod)

ans = 0
for i in range(n-1):
    ans += ((acc[-1]-acc[i+1])*A[i])% mod
    ans %= mod

print(ans)