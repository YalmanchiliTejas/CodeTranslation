n = int(input())
a = list(map(int, input().split()))

mod = 10**9 + 7
ans = 0
prev = a[0]
for i in range(1, n):
    ans += (prev * a[i]) % mod
    prev += a[i]
print(ans % mod)
