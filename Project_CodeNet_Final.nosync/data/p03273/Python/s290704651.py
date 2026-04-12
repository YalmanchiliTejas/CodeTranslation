import sys

stdin = sys.stdin
inf = 1 << 60
mod = 1000000007

ni      = lambda: int(ns())
nin     = lambda y: [ni() for _ in range(y)]
na      = lambda: list(map(int, stdin.readline().split()))
nan     = lambda y: [na() for _ in range(y)]
nf      = lambda: float(ns())
nfn     = lambda y: [nf() for _ in range(y)]
nfa     = lambda: list(map(float, stdin.readline().split()))
nfan    = lambda y: [nfa() for _ in range(y)]
ns      = lambda: stdin.readline().rstrip()
nsn     = lambda y: [ns() for _ in range(y)]
ncl     = lambda y: [list(ns()) for _ in range(y)]
nas     = lambda: stdin.readline().split()

h, w = na()
a = ncl(h)

for i in range(h):
    flag = True
    for j in range(w):
        if a[i][j] != '.':
            flag = False
    
    if flag:
        for j in range(w):
            a[i][j] = '$'

for j in range(w):
    flag = True
    for i in range(h):
        if a[i][j] != '.' and a[i][j] != '$':
            flag = False
    
    if flag:
        for i in range(h):
            a[i][j] = '$'

ans = []
for i in range(h):
    ans.append([])
    for j in range(w):
        if a[i][j] != '$':
            ans[i].append(a[i][j])

for i in range(len(ans)):
    if len(ans[i]) != 0:
        print(*ans[i], sep="")