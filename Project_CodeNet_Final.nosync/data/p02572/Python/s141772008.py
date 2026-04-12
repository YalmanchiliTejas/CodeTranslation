MOD = 10**9+7

N = int(input())
A = list(map(int,input().split()))

S = sum(A) % MOD
ans = 0

for i in A:
    S -= i
    ans += S*i
    ans %= MOD

print(ans)