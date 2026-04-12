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

def dfs(k,dep):
    if dep==n:
        return 1
    sm = 0
    for i in dst[k]:
        if used[i]:
            continue
        used[i] = True
        sm += dfs(i,dep+1)
        used[i] = False
    return sm

n,m = inm()
dst = {}
for i in range(m):
    a,b = inm()
    if a not in dst:
        dst[a] = {}
    dst[a][b] = 1
    if b not in dst:
        dst[b] = {}
    dst[b][a] = 1
used = [False]*(n+1)
used[1] = True
print(dfs(1,1))
