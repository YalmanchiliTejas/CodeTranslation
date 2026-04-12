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

cnt = 0
while max(a)>n-1:
    sm = 0
    for i in range(n):
        j = a[i]//n
        a[i] -= j*(n+1)
        sm += j
    a = [x+sm for x in a]
    cnt += sm
#
print(cnt)
#ddprint(foo(0))
#ddprint(foo(1))
