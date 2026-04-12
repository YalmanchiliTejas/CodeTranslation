N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7
tot = sum(A)
ans = 0

for i in range(N):
    tot -= A[i]
    lin = tot * A[i]
    ans += lin % mod
    ans %= mod

print(ans)
    

