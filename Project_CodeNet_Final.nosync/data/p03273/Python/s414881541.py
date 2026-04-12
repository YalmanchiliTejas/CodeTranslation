h, w = map(int, input().split())
mat = [[0 for i in range(w)] for j in range(h)]
for i in range(h):
    mat[i] = list(input())

row = []
col = []
for y in range(h):
    cnt = 0
    for x in range(w):
        if mat[y][x] == ".":
            cnt += 1
    if cnt == w:
        row.append(y)

for x in range(w):
    cnt = 0
    for y in range(h):
        if mat[y][x] == ".":
            cnt += 1
    if cnt == h:
        col.append(x)

for y in range(h):
    tmp = ""
    for x in range(w):
        if x not in col and y not in row:
            tmp += mat[y][x]
    if tmp != "":
        print(tmp)