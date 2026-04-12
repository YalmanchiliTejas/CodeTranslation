n = int(input())

a = [int(x) for x in input().strip().split()]

suff = []

mod = 10**9+7

s = 0
suff.append(s)
for i in range(n-1, -1, -1):
    s = (s%mod + a[i]%mod)%mod
    suff.append(s)


res = 0

for i in range(n):
    
    curr = (suff[n-1-i]%mod * a[i]%mod)%mod
    res = (res%mod + curr%mod)%mod

print(res)


