n = int(input())
a = list(map(int,input().split()))
ans = 0
if n % 2 == 0:
  b = []
  for i in range(n//2):
    ans += a[2*i]
    b.append(a[2*i+1] - a[2*i])
  #print(b)
  for i in range(1,n//2)[::-1]:
    b[i-1] += b[i]
  #print(b)
  b.append(0)
  print(ans + max(b))
else:
  b = []
  c = []
  for i in range(n//2):
    ans += a[2*i]
    b.append(a[2*i+1] - a[2*i])
    c.append(a[2*i+2] - a[2*i+1])
  for i in range(1,n//2)[::-1]:
    b[i-1] += b[i]
    c[i-1] += c[i]
  #print(b)
  #print(c)
  d = c[:]
  d[-1] = max(d[-1],0)
  for i in range(1,n//2)[::-1]:
    d[i-1] = max(d[i-1],d[i],0)
  #print(d)
  e = []
  for i in range(n//2):
    e.append(b[i]+d[i])
  #print(ans)
  e.append(0)
  print(ans + max(e))