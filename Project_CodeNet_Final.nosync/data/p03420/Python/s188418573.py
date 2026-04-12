n,k = map(int,input().split())
t = 0
for b in range(k+1,n+1):
  p,q = divmod(n,b)
  t += p*max(0,b-k) + max(0,q-k+1)
if k == 0:
  t -= n
print(t)