mod = 1000000007
n = int(input())
a = list(map(int,input().split()))
ans = 0
ans += (sum(a)*sum(a))%mod
for i in range(n):
    ans -= (a[i]*a[i])%mod
    if ans < 0:
        ans += mod
ans *= (mod + 1) // 2
ans %= mod
print(int(ans))