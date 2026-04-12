H, W = map(int, input().split())
a = []
y = 0
while True:
    if y >= H:
        break
    x = 0
    A = list(input())
    cnt = 0
    while True:
        if x >= W:
            break
        if A[x] == ".":
            cnt += 1
        x += 1
    if cnt == W:
        H -= 1
    else:
        a.append(A)
        y += 1
x = 0
while True:
    if x >= W:
        break
    y = 0
    cnt = 0
    while True:
        if y >= H:
            break
        if a[y][x] == ".":
            cnt += 1
        y += 1
    if cnt == H:
        for i in range(H):
            del a[i][x]
        W -= 1
    else:
        x += 1

for i in range(H):
    for j in range(W):
        print(a[i][j], end = "")
    print()
