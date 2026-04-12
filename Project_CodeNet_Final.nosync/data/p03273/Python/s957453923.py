import sys
readline = sys.stdin.readline
sys.setrecursionlimit(10**8)
mod = 10**9+7
#mod = 998244353
INF = 10**18
eps = 10**-7

H,W = map(int,readline().split())
a = [readline().rstrip() for i in range(H)]

h = [True] * H
w = [True] * W

for i in range(H):
    if a[i] == "."*W:
        h[i] = False
for i in range(W):
    if all(a[j][i] == "." for j in range(H)):
        w[i] = False
ans = []
for i in range(H):
    s = ""
    for j in range(W):
        if h[i] and w[j]:
            s += a[i][j]
    if s != "":
        ans.append(s)
for s in ans:
    print(s)

