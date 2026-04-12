from operator import mul
from functools import reduce

def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under
N = int(input())
K = int(input())
L = len(str(N))
S = str(N)
if K>L:
  print(0)
  import sys
  sys.exit()
if K==1:
  s = ['0']*L
  cnt = 0
  for i in range(L):
    for j in range(1,10):
      s[i] = str(j)
      x = ''.join(s)
      x = int(x)
      if x<=N:
        cnt += 1
      s[i] = '0'
elif K==2:
  s = ['0']*L
  cnt = 0
  for i in range(L-1):
    for j in range(i+1,L):
      for a in range(1,10):
        for b in range(1,10):
          s[i] = str(a)
          s[j] = str(b)
          x = ''.join(s)
          x = int(x)
          if x<=N:
            cnt += 1
          s[i] = '0'
          s[j] = '0'
else:
  s = ['0']*L
  cnt = 0
  cnt += cmb(L-1,3)*(9**3) if L>3 else 0
  g = int(S[0])
  s[0] = S[0]
  for i in range(1,L-1):
    for j in range(i+1,L):
      for a in range(1,10):
        for b in range(1,10):
          s[j] = str(a)
          s[i] = str(b)
          x = ''.join(s)
          x = int(x)
#          print(x)
          if x<=N:
            cnt += g
          else:
            cnt += g-1
          s[i] = '0'
          s[j] = '0'
print(cnt)