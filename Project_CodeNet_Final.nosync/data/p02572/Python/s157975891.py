n = int(input())
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

sqsum = 0
asum = 0
for a in A:
  sqsum += a**2
#  sqsum %= MOD
  asum += a
#  asum %= MOD

ans = ((asum ** 2) - sqsum) // 2
ans %= MOD

print(ans)