n= int(input())
mod=10**9+7
a= [int(x ) for x in input().split()]
b= a[:]

s=0
for i in range(n-2,-1,-1):
    b[i]=b[i+1]+b[i]
for i in range(n):
    s += (b[i]-a[i])*a[i]
print(s%mod)