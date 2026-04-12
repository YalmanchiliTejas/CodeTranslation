n = int(input())
a = list(map(int,input().split()))

mod = 10**9 + 7
ans = 0

b = [a[0]]
for i in range(n-1):
    b.append((b[-1] + a[i+1]) % mod)

for i in range(n-1):
    ans += a[i] * (b[-1] - b[i])
    ans %= mod

print(ans)
