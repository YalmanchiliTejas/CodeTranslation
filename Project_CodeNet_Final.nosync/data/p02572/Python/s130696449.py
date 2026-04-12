N = int(input())
Alist = list(map(int, input().split()))

MOD = 1000000007

Alist = Alist[::-1]

mod = 0

ans = 0
for n in range(N-1):
    mod += (Alist[n]%MOD)
    mod = mod % MOD
    ans += (Alist[n+1] * mod)%MOD

print(ans%MOD)