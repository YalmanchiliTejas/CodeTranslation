H, W = map(int, input().split())
A = [input() for i in range(H)]
P = [0]*H; Q = [0]*W
for i in range(H):
    P[i] = all(A[i][j] == '.' for j in range(W))
for i in range(W):
    Q[i] = all(A[j][i] == '.' for j in range(H))
for i in range(H):
    if P[i]:
        continue
    r = []
    for j in range(W):
        if Q[j]:
            continue
        r.append(A[i][j])
    print(*r, sep='')