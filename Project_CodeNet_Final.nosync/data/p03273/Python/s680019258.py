H,W = (int(i) for i in input().split())

a = []
for i in range(H):
    tmpinput = input()
    tmp = []
    for j in range(W):
        tmp.append(tmpinput[j])
    a.append(tmp)

yoko = []
for i in range(H):
    shiro = True
    for j in range(W):
        if a[i][j] != ".":
            shiro = False
    if shiro:
        yoko.append(i)

tate = []
for i in range(W):
    shiro = True
    for j in range(H):
        if a[j][i] != ".":
            shiro = False
    if shiro:
        tate.append(i)

for i in range(H):
    tmp = ""
    for j in range(W):
        if (j not in tate) and (i not in yoko):
            tmp = tmp + a[i][j]
    if tmp != "":
        print(tmp)