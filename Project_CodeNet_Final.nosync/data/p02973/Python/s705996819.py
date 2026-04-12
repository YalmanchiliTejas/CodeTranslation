import sys
input = sys.stdin.readline
def nibun_right(a, x):
 lo, hi = 0, len(a)
 while lo < hi:
  mid = (lo+hi)//2
  if x < a[mid]: hi = mid
  else: lo = mid+1
 return lo
def nibun_left(a, x):
 lo, hi = 0, len(a)
 while lo < hi:
  mid = (lo+hi)//2
  if a[mid] < x: lo = mid+1
  else: hi = mid
 return lo
N=int(input())
ans=[1]*N
for i in range(N):
 x=int(input())
 c=nibun_right(ans, -x)
 ans[c]=-x
c=nibun_left(ans, 1)
print(c)