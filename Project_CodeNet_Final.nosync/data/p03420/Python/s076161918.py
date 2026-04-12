n,k = [int(i) for i in input().split()]
ans = 0
for i in range(k+1,n+1):
  m = (n+1)//i
  ans += (i-k)*m
  if m*i+k <= n:
    ans += (n+1-m*i-k)
if k == 0:
  ans -= n
print(ans)