h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
res4row = []
res4col = []
res = [[]]

for j, row in enumerate(a):

    tf = False
    for el in row:
        if el == '#':
            tf = True
    if tf is True:
        res4row.append(j)

for k, col in enumerate(a[0]):
    tf2 = False
    for row2 in a:
        if row2[k] == '#':
            tf2 = True
    if tf2 is True:
        res4col.append(k)

res = [[] for z in range(h)]
for num4row in res4row:
    # res.append([])
    for num4col in res4col:
        res[num4row].append(a[num4row][num4col])

for r in res:
    st = ''
    if len(r) != 0:
        for c in r:
            st = st + c
        print(st)