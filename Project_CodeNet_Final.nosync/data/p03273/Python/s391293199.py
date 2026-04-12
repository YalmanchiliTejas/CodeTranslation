H, W = map(int, input().split())
matrix = []
hd = []
wd = []

for i in range(H):
    h = list(input())
    matrix.append(h)
    if h == ["."] * W:
        continue
    hd.append(i)

for i in range(W):
    w = [list(w_[i]) for w_ in matrix]
    if w == [["."]] * H:
        continue
    wd.append(i)

ansmatrix = []
row = []
for i in hd:
    for j in wd:
        row.append(matrix[i][j])
    ansmatrix.append(row)
    row = []

for ansrow in ansmatrix:
    print("".join(ansrow))