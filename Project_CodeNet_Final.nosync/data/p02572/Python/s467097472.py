n = int(input())
a = list(map(int, input().split()))
s = [0] * n
s[n - 1] = a[n - 1]
for i in range(n - 2, -1, -1):
    s[i] = s[i + 1] + a[i]
    
ans = 0
mod = 10 ** 9 + 7
for i in range(n - 1):
    ans += a[i] * s[i + 1]
print(ans % mod)