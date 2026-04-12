# B - Grid Compression

H, W = map(int, input().split())
A = []
for i in range(H):
    A.append(list(str(input())))

h = [0] * H
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            h[i] = 1
            continue

w = [0] * W
for j in range(W):
    for i in range(H):
        if A[i][j] == '#':
            w[j] = 1
            continue

for i in range(H):
    ans = ''
    if h[i] == 0:
        continue
    for j in range(W):
        if w[j] == 0:
            continue
        else:
            ans += A[i][j]
    print(ans)
