import sys
import bisect
input = sys.stdin.readline
n = int(input().strip())
q = [-int(input().strip())]
qapp = q.append
bis_r = bisect.bisect_right
for i in range(n-1):
  a = -int(input().strip())
  if q[-1] <= a:
    qapp(a)
  else:
    b = bis_r(q,a)
    q[b] = a
print(len(q))