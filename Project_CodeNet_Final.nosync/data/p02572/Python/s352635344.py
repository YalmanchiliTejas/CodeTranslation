import sys
import math
def Ii():return int(sys.stdin.readline().rstrip())
def Mi():return map(int,sys.stdin.readline().split())
def Li():return list(map(int,sys.stdin.readline().split()))
n = Ii()
a = Li()
sa = 0
ans = 0
mod = 10**9+7
for i in range(n-1):
  sa += a[i]
  ans += sa*a[i+1]
  ans %= mod
  
print(ans)