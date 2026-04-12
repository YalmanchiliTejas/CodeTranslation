n = int(input())
a = [int(input()) for i in range(n)]
a.sort()

if n%2 == 0:
  ans = 2*sum(a[n//2+1:]) - 2*sum(a[:n//2-1]) + a[n//2] - a[n//2-1]
  print (ans)
else:
  b = 2*sum(a[n//2+1:]) - 2*sum(a[:n//2-1]) - a[n//2] - a[n//2-1]
  c = 2*sum(a[n//2+2:]) - 2*sum(a[:n//2]) + a[n//2] + a[n//2+1]
  print (max(b,c))