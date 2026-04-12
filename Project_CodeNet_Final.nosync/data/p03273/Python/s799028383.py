H,W = map(int,input().split(" "))
field = []
row_0 = ["." for i in range(W)]
for i in range(H):
    row_i = list(input())
    if row_i == row_0:
        H -= 1
    else:
        field.append(row_i)
col_0 = ["." for i in range(H)]
for i in range(W)[::-1]:
    col_i = []
    for j in range(H):
        col_i.append(field[j][i])
    if col_i == col_0:
        for j in range(H):
            del field[j][i]

for i in range(len(field)):
    print("".join(field[i]))