H, W = map(int, input().split())
a = [input() for _ in range(H)]
row = []
col = []
for i in range(H):
    if a[i] != '.' * W:
        row.append(i)
for j in range(W):
    if any(a[i][j] == '#' for i in range(H)):
        col.append(j)
ans = [''.join(a[r][c] for c in col) for r in row]
print(*ans, sep='\n')