n = int(input())
a = list(map(int, input().split()))
t = 0
r = 0
mod = 10**9+7
for i in range(n-1, 0, -1):
    r += a[i]
    t += a[i-1]*r
print(t%mod)