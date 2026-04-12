n,*a = map(int,open(0).read().split())
a.sort()
l = 0
r = n-1
b = [a[0],a[n-1]]
ans = abs(b[0]-b[1])
while(r-l>1):
  c = max([(abs(a[i]-b[j]),i,j) for i in (l+1,r-1) for j in (0,1)])
  ans += c[0]
  b[c[2]] = a[c[1]]
  if c[1] == l+1:
    l += 1
  else:
    r -= 1
print(ans)