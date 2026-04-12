H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

hl = []
wl = []
for h in range(H):
    if sum([0 if i == "." else 1 for i in A[h]]) > 0:
        hl.append(h)

for w in range(W):
    if sum([0 if A[i][w] == "." else 1 for i in range(H)]) > 0:
        wl.append(w)

for h in hl:
    line = []
    for w in wl:
        line.append(A[h][w])
    print(*line, sep="")
