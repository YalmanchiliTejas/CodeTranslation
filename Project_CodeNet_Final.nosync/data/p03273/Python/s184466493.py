H, W = map(int, input().split())
a = []
for i in range(H):
    s = input()
    a.append(s)

isUseRow = [True] * H
isUseCol = [True] * W

for i in range(H):
    isDelete = True
    for j in range(W):
        if(a[i][j] == '#'):
            isDelete = False
    if(isDelete == False):
        isUseRow[i] = False
for i in range(W):
    isDelete = True
    for j in range(H):
        if(a[j][i] == '#'):
            isDelete = False
    if(isDelete == False):
        isUseCol[i] = False

for i in range(H):
    s = ''
    for j in range(W):
        if(isUseRow[i] == False and isUseCol[j] == False):
            s += a[i][j]
    if(s != ''):
        print(s)