n = int(input())
a = list(map(int, input().split()))
s = [0]
ans = 0
MOD = 1000000007
for i in range(0, n, 1):
    s.append((s[i] + a[i]) % MOD)

for i in range(0, n, 1):
    ans += ((s[n] - s[i + 1]) * a[i]) % MOD

print(ans % MOD)
