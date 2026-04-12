H, W = list(map(int, input().split()))

grid_compred = []
for i in range(H):
    a = input()
    if a != "." * W:
        grid_compred.append(a)

rm_list = []
for i in range(W):
    candidate = [grid_compred[jth][i] for jth in range(len(grid_compred))]
    if ''.join(candidate) == "." * len(grid_compred):
        rm_list.append(i)

for i in range(len(grid_compred)):
    row_list = [grid_compred[i][j] for j in range(len(grid_compred[i])) if j not in rm_list]
    print(''.join(row_list))