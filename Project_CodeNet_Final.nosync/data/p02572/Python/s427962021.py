MOD = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
rs = [0]
for i in range(n):
    rs.append(rs[-1] + a[n - 1 - i])

ans = 0
for i in range(n - 1):
    ans += a[i] * rs[n - 1 - i] % MOD
print(ans % MOD)