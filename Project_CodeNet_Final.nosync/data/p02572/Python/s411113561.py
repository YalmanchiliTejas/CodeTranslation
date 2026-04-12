n = int(input())
a_ls = list(map(int, input().split()))
csum = [0] * n
now = 0
for i in range(n):
    now += a_ls[i]
    csum[i] = now

mod = 10**9+7
ans = 0
for i in range(n):
    add = a_ls[i] * ((csum[-1] - csum[i])%mod)
    add %= mod
    ans += add
    ans %= mod
print(ans%mod)
