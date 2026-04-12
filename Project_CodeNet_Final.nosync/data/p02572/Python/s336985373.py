N = int(input())
A = list(map(int, input().split()))
MOD = 1000000007
SUM = sum(A) % MOD
ans = 0

for n in A:
    SUM -= n
    SUM %= MOD
    ans += SUM * n
    ans %= MOD

print(ans)
