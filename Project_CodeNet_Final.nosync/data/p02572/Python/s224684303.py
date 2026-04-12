n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
s = 0
l = [0 for i in range(n)]
l[0] = a[0]
for i in range(1, n):
    l[i] += l[i-1]
    l[i]%=mod
    l[i] += a[i]
    l[i]%=mod
# print(l)
for i in range(1, n):
    s+=((a[i]%mod)*(l[i-1]%mod))%mod
    s%=mod
print(s)
    