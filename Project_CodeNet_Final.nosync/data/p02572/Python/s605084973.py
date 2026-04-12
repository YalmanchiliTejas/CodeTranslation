mod = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))
s = [0] * (n+1)

for i in range(n-1, 0, -1):
    s[i] = (a[i] + s[i+1]) % mod


ans = 0
for i in range(n-1):
    tmp = (a[i] * s[i+1]) % mod
    ans += tmp
    ans %= mod

print(ans)