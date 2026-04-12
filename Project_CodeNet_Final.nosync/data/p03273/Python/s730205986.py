H, W = map(int, input().split())
l = []
temp_l = [0]*H
for i in range(H):
    l.append(list(str(input())))

for i in range(H):
    flag = 1
    for j in range(W):
        if l[i][j] == '#':
            flag = 0
    if flag == 1:
        temp_l[i] = 1
        for j in range(W):
            l[i][j] = 0

for i in range(W):
    flag = 1
    for j in range(H):
        if l[j][i] == '#':
            flag = 0
    if flag == 1:
        for j in range(H):
            l[j][i] = 0


for i in range(H):
    for j in range(W):
        if temp_l[i] == 0:
            if not l[i][j] == 0:
                print(l[i][j], end='')
    if temp_l[i] == 0:
        print('')