h, w = map(int, input().split())
a = []
for i in range(h):
    tmp = list(input())
    if tmp[0] != '.' or tmp.count('.') != len(tmp):
        a.append(tmp)
b = []
for j in range(w):
    f = True
    for k in range(len(a)):
        if a[k][j] == '#':
            f = False
    else:
        if f:
            b.append(j)
for x in range(len(a)):
    for y in range(len(a[x])):
        if y not in b:
            print(a[x][y], end='')
    else:
        print('')
