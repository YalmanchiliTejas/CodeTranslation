n = int(input())
a = list(map(int, input().split()))
mod = pow(10, 9) + 7
b = [0] * (n + 1)
for i in range(n):
    b[i + 1] = a[i] + b[i]
ans = 0
for i in range(n - 1):
    ans += (b[n] - b[i + 1]) * a[i]
    ans %= mod
print(ans)