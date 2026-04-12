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
a = inl()
if n<=3:
    print(max(a))
    exit()

lacc = [0]*n
racc = [0]*n
lacc[0] = a[0]
lacc[1] = a[1]
racc[n-1] = a[n-1]
racc[n-2] = a[n-2]
for i in range(2,n):
    if i%2==0:
        lacc[i] = lacc[i-2]+a[i]
    else:
        lacc[i] = max(lacc[i-3],lacc[i-2])+a[i]
if n%2==0:
    print(max(lacc[n-2],lacc[n-1]))
    exit()
for i in range(n-3,-1,-1):
    if (n-1-i)%2==0:
        racc[i] = racc[i+2]+a[i]
    else:
        racc[i] = max(racc[i+3],racc[i+2])+a[i]
mx = max(racc[2],lacc[n-3])
for i in range(1,n-2):
    if i%2==0:
        mx = max(mx, max(lacc[i-2],lacc[i-1])+racc[i+2])
    else:
        mx = max(mx, max(racc[i+2],racc[i+3])+lacc[i-1])
print(mx)
