H, W = map(int,input().split())
mapli = []
for i in range(H):
    tmp = []
    s = str(input())
    for j in range(W):
        tmp.append(s[j])
    mapli.append(tmp)

tmp = []

for i in range(H):
    count = 0
    for j in range(W):
        if mapli[i][j] == ".":
            count += 1
    if count == W:
        tmp.append(i)
tmp.sort(reverse=True)

for i in range(len(tmp)):
    del mapli[tmp[i]]

tmp = []

for i in range(W):
    count = 0 
    if mapli[0][i] == ".": 
        for j in range(len(mapli)):
            if mapli[j][i] != ".":
                break
            count += 1
    if count == len(mapli):
        tmp.append(i)
tmp.sort(reverse=True)

for i in range(len(tmp)):
    for k in range(len(mapli)):
        del mapli[k][tmp[i]]

for i in range(len(mapli)):
    print(''.join(map(str, mapli[i])))
