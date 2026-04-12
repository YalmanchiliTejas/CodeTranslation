h,w = map(int, input().split())

strs = [input() for i in range(h)]

hFlag = []
wFlag = []

for i in range(h):
    if len(strs[i]) == len(strs[i].replace('#','')):
        wFlag.append(False)
    else:
        wFlag.append(True)

for i in range(w):
    flag = False
    for j in range(h):
        if strs[j][i] == '#':
            flag = True
            break

    if flag :
        hFlag.append(True)
    else:
        hFlag.append(False)

for i in range(h):
    if wFlag[i]:
        for j in range(w):
            if hFlag[j]:
                print(strs[i][j], end='')

        print()

