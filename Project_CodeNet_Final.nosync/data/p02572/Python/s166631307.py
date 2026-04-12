N = int(input())
A = list(map(int,input().split()))
# ((A合計**2)-ΣAそれぞれ**2)//2
mod = 10**9+7
AA = sum(A)
ans = (AA%mod)**2
ans %= mod
for a in A:
    ans -= a**2
    ans %= mod
ans %= mod
print(ans*pow(2,mod-2,mod)%mod)