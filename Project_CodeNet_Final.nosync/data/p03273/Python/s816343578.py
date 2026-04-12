H, W = map(int, input().split())
a = []
for i in range(H):
    b = input()
    a.append(b)
b = []
flag = 0
for i in range(H):
    flag = 0
    for j in range(W):
        if a[i][j] == '#':
            flag = 1
    if flag == 1:
        d = [1 for i in range(W)]
        b.append(d)
    else:
        d = [0 for i in range(W)]
        b.append(d)
for i in range(W):
    flag = 0
    for j in range(H):
        if a[j][i] == '#':
            flag = 1
    if flag == 0:
        for j in range(H):
            b[j][i] = 0

for i in range(H):
    flag = 0
    for j in range(W):
        if b[i][j] == 1:
            print(a[i][j], end = "")
            flag = 1
        if flag == 1 and j == W - 1:
            print("")