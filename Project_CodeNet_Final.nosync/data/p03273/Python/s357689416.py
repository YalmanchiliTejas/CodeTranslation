H, W = map(int, input().split())

A = [list(input()) for _  in range(H)]
h = set()
w = set()

for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            h.add(i)
            w.add(j)

for i in h:
    for j in w:
        print(A[i][j], end="")
    print()