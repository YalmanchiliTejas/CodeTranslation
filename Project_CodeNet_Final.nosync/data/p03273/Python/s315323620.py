h, w = map(int,input().split())
masu = []
for _ in range(h):
    masu.append(list(input()))

# 行から見る
row = []
column = []
for i in range(h):
    if not masu[i] == ['.'] * w:
        row.append(i)

column = []
for i in range(w):
    flg = 0
    for j in range(h):
        if masu[j][i] == '#':
            flg = 1
    if flg == 1:
        column.append(i)

for i in row:
    for j in column:
        print(masu[i][j],end='')
    print()