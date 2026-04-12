H, W = map(int, input().split())
a = []
for i in range(H):
    a.append(list(input()))
for i in range(W):
    flag = True
    for j in range(H):
        if a[j][i] == '#':
            flag = False
    if flag:
        for k in range(H):
            a[k][i] = '-'
for i in a:
    if not '#' in i:
        continue
    for j in range(W):
        if i[j] != '-':
            print(i[j], end = '')
    print('')
