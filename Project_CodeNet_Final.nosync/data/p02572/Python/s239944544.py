n = int(input())
a = [int(i) for i in input().split()]
b = [a[0]]
ans = 0
mod = 1000000007

for i in range(1,n):
  b.append(b[-1]+a[i])

for i in range(1,n):
  ans += a[n-i]*b[n-i-1]
  ans = ans % mod
  
print(ans)