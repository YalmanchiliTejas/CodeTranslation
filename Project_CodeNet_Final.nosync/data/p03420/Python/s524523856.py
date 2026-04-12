n,k = map(int,input().split())
ans = 0
if k == 0:
  print(n**2)
  exit()
for b in range(k+1,n+1):
  c,d = n//b,n%b
  ans += (b-k)*c
  ans += max(0,d-k+1)
print(ans)