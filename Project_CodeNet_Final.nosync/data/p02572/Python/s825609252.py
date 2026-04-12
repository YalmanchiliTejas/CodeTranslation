N = int(input())
A = list(map(int,input().split()))
MOD = 1000000007
S = sum(A) % MOD
ans = 0

for x in A:
    S -= x
    S %= MOD
    ans += S * x
    ans %= MOD
ans %= MOD
print(ans)