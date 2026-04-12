MOD = 1000000007
n = int(input())
a = [int(_) for _ in input().split()]
p = [0] * (n + 1)
for i in range(n - 1, -1, -1):
    p[i] = p[i + 1] + a[i]
ans = 0
for i in range(n):
    add = a[i] * (p[i] - a[i])
    add = add % MOD
    ans += add
    ans = ans % MOD
print(ans)
