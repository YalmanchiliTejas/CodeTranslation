n = int(input())
a = list(map(int, input().split()))
mod = 1000000007
b = []
for i in range(n):
  b.append(a[i])
i = n-2
while i >= 0:
  b[i] += b[i+1]
  b[i] %= mod
  i -= 1
#print(a)
#print(b)
ans = 0
for i in range(n-1):
  ans += a[i]*b[i+1]%mod
  ans %= mod
print(ans)