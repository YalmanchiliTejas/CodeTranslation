n=int(input())
a=[int(input()) for _ in range(n)]
a.sort(reverse=True)
if n%2==0:
  print(sum(a[:n//2])-sum(a[n//2:])+sum(a[:n//2-1])-sum(a[n//2+1:]))
else:
  c=sum(a[:n//2+1])+sum(a[:n//2-1])-2*sum(a[n//2+1:])
  d=2*sum(a[:n//2])-sum(a[n//2:])-sum(a[n//2+2:])
  print(max(c,d))
