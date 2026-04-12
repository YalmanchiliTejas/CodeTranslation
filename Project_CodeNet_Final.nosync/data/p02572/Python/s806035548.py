MOD = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))
b = [0] * n
for i in range(n - 1):
    b[-i - 2] = b[-i-1] + a[-i-1]
ans = 0
for i in range(n - 1):
    ans += a[i] * b[i]
print(ans % MOD)
