h,w = map(int,input().split())
a = [input() for _ in range(h)]
tmp = []
flag = True
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            flag = False
    if flag:
        tmp.append(i)
    flag = True
flag = True
tmp2 = []
for i in range(w):
    for j in range(h):
        if a[j][i] == '#':
            flag = False
    if flag:
        tmp2.append(i)
    flag = True
t = set(tmp)
t2 = set(tmp2)
for i in range(h):
    for j in range(w):
        if i not in t and j not in t2:
            print(a[i][j],end='')
    if i not in t:
        print()
