n,k = map(int,input().split())
a,p = [1],[1]
for i in range(n):
  a.append(a[i]*2+3)
  p.append(p[i]*2+1)
def f(n,k):
  if n == 0:
    if k == 0:
      return 0
    else:
      return 1
  if k == 0:
    return 0
  elif k <= a[n-1]+1:
    return f(n-1,k-1)
  else:
    return p[n-1]+1+f(n-1,k-2-a[n-1])
print(f(n,k))

