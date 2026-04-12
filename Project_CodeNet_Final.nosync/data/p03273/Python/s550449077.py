H, W = [int(x) for x in input().split()]
rows = [input() for _ in range(H)]
lst = []
tmp = []
for row in rows:
    if '#' in row: lst.append(row)
for i in range(W):
    column = ''
    for row in lst:
        column += row[i]
    if '#' not in column: 
        tmp.append(i)
for row in lst:
    for i in range(W):
        if (i in tmp): continue
        print(row[i], end='')
    print()
