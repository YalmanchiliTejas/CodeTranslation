h, w = map(int, input().split())
l = [input() for i in range(h)]
idh=[]
idw=[]

for i in range(w):
    fl = True
    for j in range(h):
        if l[j][i]=='#':
            fl=False
    if fl:
        idw.append(i)
for i in range(h):
    if l[i].count('#')==0:
        idh.append(i)
for i in range(h):
    if i in idh:
        continue
    for j in range(w):
        if j in idw:
            continue
        print(l[i][j], end='')
    print('')