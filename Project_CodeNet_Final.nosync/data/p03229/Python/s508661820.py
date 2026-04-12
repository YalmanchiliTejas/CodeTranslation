printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

n = inn()
a = []
for i in range(n):
    a.append(inn())
a.sort()
if n%2==0:
    m = n//2
    sa = sum(a[:m])
    sb = sum(a[m:])
    print(2*sb-2*sa-a[m]+a[m-1])
else:
    m = n//2
    sa = sum(a[:m])
    sb = sum(a[m+1:])
    if a[m+1]-a[m]>a[m]-a[m-1]:
        print(2*sb-2*sa-a[m]+a[m-1])
    else:
        print(2*sb-2*sa-a[m+1]+a[m])
