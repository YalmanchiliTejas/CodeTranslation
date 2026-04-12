h, w = map(int, input().split())
a = [[0]*w]*h
for i in range(h):
    a[i] = input()

c, l = [], []
for i in range(h):
    flag = True
    for j in range(w):
        if a[i][j] != '.':
            flag = False
            break
    if not flag:
        l.append(i)

for i in range(w):
    flag = True
    for j in range(h):
        if a[j][i] != '.':
            flag = False
            break
    if not flag:
        c.append(i)

for i in range(len(l)):
    s = ''
    for j in range(len(c)):
        s += a[l[i]][c[j]]
    print(s)