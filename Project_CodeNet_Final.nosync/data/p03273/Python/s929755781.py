H,W = map(int, input().split())

a = [list(input()) for _ in range(H)]

i = 0
while i < H:
    for j in range(W):
        if a[i][j] != '.':
            break
    else:
        a.pop(i)
        H -= 1
        continue
    i += 1

i = 0
while i < W:
    for j in range(H):
        if a[j][i] != '.':
            break
    else:
        for k in range(H):
            a[k].pop(i)
        W -= 1
        continue
    i += 1

for i in range(H):
    for j in range(W):
        print(a[i][j], end='')
    print()
