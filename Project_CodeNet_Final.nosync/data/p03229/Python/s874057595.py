import sys
input = sys.stdin.readline
n = int(input())
chk = []
for i in range(n):
  a = int(input())
  chk.append(a)
chk.sort()
if n%2 == 0:
  l = [i*2 for i in chk[:n//2]]
  r = [i*2 for i in chk[n//2:]]
  print(sum(r)-sum(l)+chk[n//2-1]-chk[n//2])
else:
  l = [i*2 for i in chk[:(n-1)//2]]
  r = [i*2 for i in chk[(n-1)//2+1:]]
  p = sum(r)-sum(l)+chk[(n-1)//2-1]-chk[(n-1)//2]
  q = sum(r)-sum(l)+chk[(n-1)//2]-chk[(n-1)//2+1]
  print(max(p,q))