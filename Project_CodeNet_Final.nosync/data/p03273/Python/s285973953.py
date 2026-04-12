H, W = map(int, input().rstrip().split())
a = [list(input()) for _ in range(H)]
a_int = []
for i in range(H):
    tmp = [1 if a[i][j] == "#" else 0 for j in range(W)]
    a_int.append(tmp)
column = []
row = []
for i in range(H):
    if sum(a_int[i])==0:
        row.append(i)
for i in range(W):
    total = 0
    for j in range(H):
        total += a_int[j][i]
    if total == 0:
        column.append(i)
row.reverse()
column.reverse()
for i in row:
    a.pop(i)
for i in column:
    for j in range(len(a)):
        a[j].pop(i)
for S in a:
    print(*S, sep ="")