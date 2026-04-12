n = int(input())
la = list(map(int, input().split()))
MOD = (10**9+7)
ans = 0
nn = 0
for i in range(n):
  ans %= MOD
  ans += la[i]%MOD
  nn %= MOD
  nn += (la[i]**2)%MOD
ans = (ans**2-nn+10**9+7)*pow(2, -1, MOD)%MOD
print(ans)