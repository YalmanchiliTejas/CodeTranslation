n = int(input())
a = tuple(map(int,input().split()))
t = 0
mod = 10**9 + 7
at = []
for j in range(1,n):
  t += a[n-j] % mod 
  at.append(t)

ans = 0
for i in range(n-1):
  ans += at[n-2-i] *a[i]
print(ans % mod)