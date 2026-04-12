#from collections import deque,defaultdict
printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7
#R = 998244353

def ddprint(x):
  if DBG:
    print(x)

n,x,m = inm()
k = -1
a = x
h = {}
f = [-1]*100001
f[0] = a
h[a] = 0
for i in range(1,n):
    a = (a*a)%m
    f[i] = a
    if a in h:
        k = i
        j = h[a]
        break
    else:
        h[a] = i
#ddprint(f"{f[:15]}")
if k<0:
    print(sum(f[:n]))
else:
    p = k-j
    q = (n-j)//p
    r = (n-j)%p
    #ddprint(f" /{k=} {j=} {f[j]} {f[k]} {p=} {q=} {r=}")
    print(sum(f[:j+r])+q*sum(f[j:k]))
