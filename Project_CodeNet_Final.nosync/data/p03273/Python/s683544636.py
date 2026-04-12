H, W = [int(i) for i in input().split()]
A = [input() for j in range(H)]

DH = set()
DW = set()

for h in range(H):
    for w in range(W):
        if A[h][w] == '#':
            DH.add(h)
            DW.add(w)

for h in range(H):
    if h in DH:
        for w in range(W):
            if w in DW:
                print(A[h][w], end='')
        print()