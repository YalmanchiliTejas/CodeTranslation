n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
listsum = sum(a)
kotae = 0
for i in range(n-1):
    listsum -= a[i]
    kotae += listsum*a[i]%mod

print(kotae%mod)