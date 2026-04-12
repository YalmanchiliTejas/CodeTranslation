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

n = inn()
a = inl()
acc = [0]*(n+1)
for i in range(n-1,-1,-1):
    acc[i] = acc[i+1]+a[i]
#ddprint(acc)
x = 0
for i in range(n-1):
    #ddprint(f"{x=} {i=} {acc[i+1]}")
    x = (x+a[i]*acc[i+1])%R
print(x)
