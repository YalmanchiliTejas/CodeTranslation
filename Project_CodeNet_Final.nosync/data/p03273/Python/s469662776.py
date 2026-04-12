H, W = map(int, input().split())
field = [input() for _ in range(H)]
comp_rows = []
comp_cols = []
for i in range(H):
    if field[i] == "." * W:
        comp_rows.append(i)
for j in range(W):
    if "".join(field[i][j] for i in range(H)) == "." * H:
        comp_cols.append(j)
for i in range(H):
    if i in comp_rows:
        continue
    print("".join(field[i][j] for j in range(W) if j not in comp_cols))
