import sys
 
stdin = sys.stdin
inf = 1 << 60
mod = 1000000007
 
ni = lambda: int(ns())
nin = lambda y: [ni() for _ in range(y)]
na = lambda: list(map(int, stdin.readline().split()))
nan = lambda y: [na() for _ in range(y)]
ns = lambda: stdin.readline().rstrip()
nsn = lambda y: [ns() for _ in range(y)]
nsl = lambda y: [list(ns()) for _ in range(y)]
nas = lambda: stdin.readline().split()

H, W = na()
m = nsl(H)

for i in range(W):
    flag = True
    for j in range(H):
        if m[j][i] != '.':
            flag = False
    if flag:
        for j in range(H):
            m[j][i] = '$'

for i in range(H):
    flag = True
    for j in range(W):
        if m[i][j] != '.' and m[i][j] != '$':
            flag = False
    if flag:
        for j in range(W):
            m[i][j] = '$'

o = [[] for i in range(H)]
for i in range(H):
    for j in range(W):
        if m[i][j] != '$':
            o[i].append(m[i][j])

for i in o:
    if len(i) >= 1:
        for j in i:
            print(j, end="")
        print()