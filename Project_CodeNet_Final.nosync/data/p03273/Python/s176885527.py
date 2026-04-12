h, w = map(int, raw_input().split())
arr = []
del_row = 0
for i in range(h):
    row = raw_input()
    if row != ("."*w):
        arr.append(row)
    else:
        del_row += 1
ans = []
for j in range(w):
    column = []
    for k in range(h-del_row):
        column.append(arr[k][j])
    if column != ["." for i in range(h-del_row)]:
        ans.append(column)
for num in range(h-del_row):
    str = ""
    for lst in ans:
        str += lst[num]
    print str