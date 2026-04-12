mod = 10**9+7
half = 5*10**8+4
n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(n):
  ans += a[i]
  ans %= mod
ans **= 2
#print(ans)
ans %= mod
#print(ans)
for i in range(n):
  ans -= a[i] ** 2
  ans %= mod
ans *= half
ans %= mod
print(ans)