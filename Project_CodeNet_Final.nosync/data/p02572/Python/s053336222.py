n = int(input())
a = list(map(int,input().split()))
mod = 10**9 + 7

sum_a = 0
sum_ex = 0
for ai in a:
    sum_a += ai
    sum_a %= mod
    sum_ex += ai**2
    sum_ex %= mod

ans = (sum_a*sum_a - sum_ex)%mod
ans *= pow(2,mod-2,mod)
ans %= mod
print(ans)