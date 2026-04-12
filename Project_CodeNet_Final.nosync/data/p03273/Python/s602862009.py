H,W = map(int,input().split())

a = [list(input()) for i in range(H)]
cnt = 0
i = 0
while i < len(a):
    for j in range(W):
        if a[i][j] not in '#':
            cnt += 1
    if cnt == W:
        a.remove(a[i])
        i -= 1
        H -= 1
    cnt = 0
    i += 1
i = 0
cnt = 1
while i < W:
    if a[0][i] == '.':
        for j in range(1,H):
            if a[j][i] == '.':
                cnt += 1
        if cnt == H:
            for j in range(H):
                a[j].pop(i)
            W -= 1
            i -= 1
    cnt = 1
    i += 1
[print(''.join(a[i])) for i in range(H)]