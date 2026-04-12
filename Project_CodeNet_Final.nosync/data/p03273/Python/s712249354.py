H, W = map(int, input().split())

aLst = [list(map(str, input().split())) for i in range(H)]

deIndex = []
for i in range(H):
    if aLst[i][0].count('.') == W:
        deIndex.append(i)
deIndex.sort(reverse=True)

for i in deIndex:
    del aLst[i]
H -= len(deIndex)
deIndex.clear()

for i in range(W):
    kCnt = 0
    for j in range(H):
        if aLst[j][0][i] == '.':
            kCnt += 1

    if kCnt == H:
        deIndex.append(i)
if len(deIndex) == 0:

    for i in range(H):
        print(''.join(aLst[i]))
else:
    deIndex.sort(reverse=True)
    tmplist = [['' for i in range(W)] for j in range(H)]
    for j in range(H):
        tmplist[j] = list(aLst[j][0])

    for i in range(H):
        for j in deIndex:
            del tmplist[i][j]

    W -= len(deIndex)
    for i in range(H):
        print(''.join(tmplist[i]))