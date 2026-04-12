n,x,m = map(int,input().split())
if x == 1:
  print(n)
  exit()
u = [0 for _ in range(m)]
rs = [0 for _ in range(m+1)]
s = x
u[x] = 1
rs[1] = x
i = 2
while True:
  x = (x*x)%m
  if u[x] == 0:
    u[x] = i
    s += x
    rs[i] = s
    i += 1
  else:
    ls = u[x]
    le = i-1
    break
if n <= le:
  print(rs[n])
  exit()
ans = rs[ls-1]
ll = le-ls+1
nl = n-ls+1
lsum = rs[le] - rs[ls-1]
q = nl//ll
r = nl%ll
ans += q*lsum
ans += rs[ls-1+r] - rs[ls-1]
print(ans)