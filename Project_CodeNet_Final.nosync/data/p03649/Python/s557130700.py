N, *A = map(int, open(0).read().split())
ans = 10**30
for i in range(N):
  l = -1
  r = 10**30
  while l+1<r:
    s = (l+r)//2
    x = s*N+i
    m = sum((c+x-N+1+N)//(N+1) for c in A)
    if m>x:
      l = s
    else:
      r = s
  x = r*N+i
  m = sum((c+x-N+1+N)//(N+1) for c in A)
  if m==x:
    ans = min(ans,x)
print(ans)
