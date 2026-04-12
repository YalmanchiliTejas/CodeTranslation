H, W = map(int, input().split())
a = [input() for _ in range(H)]

h = []
w = []
for i in range(H):
    cnt = 0
    for j in range(W):
        if a[i][j] == '.':
            cnt += 1
    if cnt == W:
        h.append(i)

for j in range(W):
    cnt = 0
    for i in range(H):
        if a[i][j] == '.':
            cnt += 1
    if cnt == H:
        w.append(j)

for i in range(H):
    if i in h:
        continue
    for j in range(W):
        if j in w:
            continue
        print(a[i][j],end='')
    print()