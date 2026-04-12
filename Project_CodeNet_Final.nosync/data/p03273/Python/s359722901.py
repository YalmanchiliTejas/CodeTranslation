H, W = map(int, input().split())
a = [list(input()) for i in range(H)]

cntH = 0
for i in range(H-1, -1, -1):
    flag = True
    for j in range(W):
        if a[i][j] == '#':
            flag = False
            break
    if flag:
        a.pop(i)
        cntH+=1

for j in range(W-1, -1, -1):
    flag = True
    for i in range(H-cntH):
        if a[i][j] == '#':
            flag = False
    if(flag):
        for i in range(H-cntH):
            a[i].pop(j)

for i in range(H-cntH):
    for j in range(len(a[i])):
        print(a[i][j], end='')
    print('')