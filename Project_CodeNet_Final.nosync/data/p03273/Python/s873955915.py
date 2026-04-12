H, W = [int(i) for i in input().split()]
A = [input() for j in range(H)]

DH = []

for h in range(H):
    for w in range(W):
        if A[h][w] == '#':
            break
    else:
        DH.append(h)

DW = []

for w in range(W):
    for h in range(H):
        if A[h][w] == '#':
            break
    else:
        DW.append(w)

for h in range(H):
    for w in range(W):
        if h in DH:
            break
        elif w in DW:
            continue
        print(A[h][w], end='')
    else:
        print()