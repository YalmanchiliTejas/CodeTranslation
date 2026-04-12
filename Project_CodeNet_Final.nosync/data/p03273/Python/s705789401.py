h,w = map(int, input().split())
a = []
row_check = []
for i in range(h): #横が消える
    tmp = list(input())
    a.append(tmp)
    if '#' in tmp:
        row_check.append(i)
col_check = []
for i in range(w):
    columns =[]
    for j in range(h):
        columns.append(a[j][i])
    if '#' in columns:
        col_check.append(i)
res = []
for i in range(h):
    if i in row_check:
        tmp = []
        for j in range(w):
            if j in col_check:
                tmp.append(a[i][j])
        print(''.join(tmp))
