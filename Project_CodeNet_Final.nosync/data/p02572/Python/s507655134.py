N = int(input())
a = [int(s) for s in input().split()]
ans = int(0)
temp = int(0)
MOD = int(1000000007)
sumari = sum(a)

for i in range(N-1):
  sumari = sumari - a[i] 
  temp = sumari % MOD
  temp = temp * a[i]
  temp = temp % MOD
  ans += temp
  ans = ans % MOD
print(ans)