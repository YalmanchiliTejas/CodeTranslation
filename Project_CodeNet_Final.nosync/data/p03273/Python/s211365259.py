H, W = map(int, input().split())

n_black_col = [0]*W
n_black_row = []

inp = []
for row in range(H):
    tmp = input()
    inp.append(tmp)
    r =[1 if a == "." else 0 for a in tmp]
    n_black_col = [n_black_col[i] + r[i] for i in range(W)]
    n_black_row.append(sum(r))

remove_col = []
remove_row = []
for ind, i in enumerate(n_black_col):
    if i == H:
        remove_col.append(ind)
for ind, i in enumerate(n_black_row):
    if i == W:
        remove_row.append(ind)

for i in range(H):
    if i in remove_row:
        continue
    str = ""
    for j in range(W):
        
        if j in	remove_col:
            continue
        str += inp[i][j]
    print(str)









