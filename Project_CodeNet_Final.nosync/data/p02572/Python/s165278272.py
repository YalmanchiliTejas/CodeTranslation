n=int(input())
L=[int(x) for x in input().split()]
sum=0
product=0
mod=1000000007
for i in range(n):
    sum+=L[i]%mod
for i in range(n-1):
    sum-=(L[i]%mod)
    product+=sum*(L[i]%mod)
print(product%mod)