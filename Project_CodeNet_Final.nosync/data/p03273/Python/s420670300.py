H, W = map(int, input().split())
a = [input() for _ in range(H)]
for i in range(H):
    if a[i].count('#') > 0:
        s = ''
        for j in range(W):
            if [A[j] for A in a].count('#') > 0:
                s += a[i][j]
        print(s)
