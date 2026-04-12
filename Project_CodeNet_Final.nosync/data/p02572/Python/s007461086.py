n = int(input())
a = list(map(int, input().split()))

mod = 10**9+7
s = 0
nizyo = 0

for i in range(n):
    s += a[i]
    #s %= mod

for i in range(n):
    nizyo += a[i]**2
    #nizyo %= mod

print(((s**2 - nizyo)//2)%mod)