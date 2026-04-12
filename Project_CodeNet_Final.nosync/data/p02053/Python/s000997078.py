# from sys import exit
H, W = [int(n) for n in input().split()]
c = [[0 for _ in range(W)] for __ in range(H)]
Bs = []

for i in range(H):
    c[i] = list(str(input()))
    for j in range(W):
        if c[i][j] == "B":
            Bs.append((i, j))

INF = 10e10
a, c = -INF, -INF
b, d = INF, INF
for e in Bs:
    a = max(e[0] - e[1], a)
    b = min(e[0] - e[1], b)
    c = max(e[0] + e[1], c)
    d = min(e[0] + e[1], d)
print(max(a-b, c-d))

