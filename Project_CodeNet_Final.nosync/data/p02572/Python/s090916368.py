n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
suma = sum(a)%mod
result = 0
for i in range(n-1):
    temp = a[i]
    suma -= (a[i]%mod)
    result += (suma * (a[i])%mod)%mod
print(result % mod)