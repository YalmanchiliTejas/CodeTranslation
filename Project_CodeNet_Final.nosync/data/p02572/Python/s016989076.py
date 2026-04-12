n = int(input())
a = list(map(int, input().split()))
s, mod = sum(a)-a[0], 1000000007
ans = a[0]*s
for i in range(1, n):
    s -= a[i]
    ans = (ans % mod + ((s % mod) * a[i]) % mod) % mod

print(ans % mod)
