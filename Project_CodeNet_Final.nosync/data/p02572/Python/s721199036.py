n = int(input())
li = list(map(int,input().split()))
mod = 10**9+7

ans = 0
k = 0
for i in range(1,n):
    k += li[i-1]
    ans += k*li[i]
    ans = ans % mod
print(ans%mod)
    