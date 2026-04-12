from sys import stdin
input = stdin.readline

n = int(input().rstrip())
a = list(map(int, input().rstrip().split()))

MOD = 1000000007
ans = 0

k = 0
s = [0] * n
for i in range(n-1, 0, -1):
    k += a[i] % MOD
    s[i] = k

for i in range(n-1):
    ans += a[i] * s[i+1]

ans = ans % MOD

print(ans)