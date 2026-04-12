n = int(input())
a = list(map(int,input().split()))
mod = 10**9+7
aa = 0
b = 0
for i in range(n):
    aa += a[i] ** 2  
    b += a[i]
    #aa %= mod
    #b %= mod
print((b ** 2 - aa)//2%mod)
