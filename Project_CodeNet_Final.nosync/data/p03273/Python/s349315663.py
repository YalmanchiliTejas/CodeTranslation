H,W = map(int,input().split())
A = [input() for i in range(H)]

tate = set(range(H))
yoko = set(range(W))

for i in range(H):
    for j in range(W):
        if A[i][j] == "#":
            break
    else:
        tate.remove(i)

for i in range(W):
    for j in range(H):
        if A[j][i] == "#":
            break
    else:
        yoko.remove(i)

B=[[A[i][j] for i in tate] for j in yoko]
C=[""]*(len(list(tate)))

for i in range(len(list(tate))):
    for j in range(len(list(yoko))):
        C[i] += B[j][i]

for i in range(len(list(tate))):
    print(C[i])