n = int(input())
As = list(map(int, input().split()))
MOD = 10**9 + 7
S = sum(As)%MOD
ans = 0
for a in As:
    ans += (a * (S-a))%MOD
    ans %= MOD
ans *= pow(2,MOD-2,MOD)
print(ans%MOD)
