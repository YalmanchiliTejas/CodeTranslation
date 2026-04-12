h, w = map(int, input().split())
A = [ input() for _ in range(h) ]
H, W = [], []
for i in range(h):
    if A[i].count('.')==w:
        H.append(i)
for j in range(w):
    if [ A[i][j] for i in range(h) ].count('.')==h:
        W.append(j)
for i in range(h):
    if i in H:
        continue
    for j in range(w):
        if j in W:
            continue
        print(A[i][j], end='')
    print()