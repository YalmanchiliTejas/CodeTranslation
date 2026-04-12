H, W = map(int,input().split())
A = []
for _ in range(H):
    A.append(list(input()))
col = []
row = []
for i in range(H):
    if not '#' in A[i]:
        row.append(i)
for i in range(W):
    flag = 1
    for j in range(H):
        if '#' == A[j][i]:
            flag = 0
    if flag:
        col.append(i)
for i in range(H):
    if i in row:
        continue
    for j in range(W):
        if j in col:
            continue
        print(A[i][j], end='')
    print()