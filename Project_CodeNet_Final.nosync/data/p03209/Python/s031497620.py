import sys
sys.setrecursionlimit(10 ** 9)

N,X = map(int,input().split())
L = [1 for _ in range(N+1)]
for i in range(1,N+1):
  L[i] = L[i-1] *2 + 3
#print(L)

def patty(l,x):
  if l == 0:
    res = 1
  else:
    if x == 1:
      res = 0
    elif 2 <= x <= L[l-1]+1:
      res = patty(l-1,x-1)
    elif x == L[l-1]+2:
      res = patty(l-1,L[l-1])+1
    elif L[l-1]+3 <= x <= L[l-1]*2+2:
      res = patty(l-1,L[l-1])+1+patty(l-1,x-L[l-1]-2)
    else:
      res = patty(l-1,L[l-1])*2+1
  return res

print(patty(N,X))
