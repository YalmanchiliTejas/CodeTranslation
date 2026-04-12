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

n,k = inm()
if k==0:
    print(n*n)
    exit()
sm = 0
for i in range(k+1,n+1):
    sm += (i-k)*(n//i)+max(0,n+1-(n//i)*i-k)
    #ddprint(f"sm {sm} i {i} n//i {n//i} t1 {(i-k)*(n//i)} t2 {n+1-k-(n//i)*i}")
print(sm)
