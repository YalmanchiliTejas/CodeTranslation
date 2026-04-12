import sys,heapq,math,resource,bisect
from collections import deque,defaultdict
printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True # and False
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

def setrlim():
  sys.setrecursionlimit(250000)
  soft,hard = resource.getrlimit(RLIMIT_STACK)
  # setrlimit works on ubuntu (and atcoder), but not on WSL
  #resource.setrlimit(RLIMIT_STACK, (128*1024*1024,hard))

n = inn()
a = []
for i in range(n):
    a.append(inn())
b = [a[n-1]]
for i in range(n-2,-1,-1):
    if a[i]>=b[-1]:
        b.append(a[i])
    else:
        j = bisect.bisect_right(b,a[i])
        b[j] = a[i]
    #ddprint(b)
print(len(b))
