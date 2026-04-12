H,W = map(int,input().split())
masu = [list(input())for i in range(H)]
excludeC = []
excludeR = []
for i in range(H):
    if masu[i].count('.') == W:
        excludeR.append(i)

for i in range(W):
    isExclude = True
    for j in range(H):
      if masu[j][i] == '#':
            isExclude = False
            break
    if isExclude:
        excludeC.append(i)

for i in range(H):
    if i in excludeR:
        continue
    for j in range(W):
        if j in excludeC:
            continue
        print(masu[i][j],end='')
    print('')

