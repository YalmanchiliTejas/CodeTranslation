H, W = map(int, input().split())
A = [input() for _ in range(H)]

h = {i: False for i in range(H)}
w = {i: False for i in range(W)}

for i in range(H):
    for j in range(W):
        if A[i][j] == "#":
            h[i] = True
            w[j] = True

for i in range(H):
    s = ""
    for j in range(W):
        if h[i] and w[j]:
            s += A[i][j]

    if s != "":
        print(s)