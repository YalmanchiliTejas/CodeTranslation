n,k = map(int,input().split())
ans = 0
if k == 0:
  print(n*n)
  exit()
for i in range(k+1,n+1):
  ans += (i-k) * (n//i)
  ans += max(n%i+1 - k, 0)
print(ans)
