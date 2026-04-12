h, w = map(int, input().split())
a = [input() for i in range(h)]
b= [1] * (h + w)

for i in range(h):
    if not a[i].count('#'):
        b[i] = 0

for i in range(w):
    flag = True
    for j in range(h):
        if a[j][i] == '#':
            flag = False
    if flag:
        b[i + h] = 0

for i in range(h):
    for j in range(w):
        if b[i] and b[j + h]:
            print(a[i][j], end = '')
    if b[i]:
        print()
