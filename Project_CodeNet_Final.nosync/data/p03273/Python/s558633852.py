H, W = map(int, input().split())

A = [input() for _ in range(H)]


def f1(x):
    for i in range(W):
        if A[x][i] == '#':
            return False
    return True


def f2(x):
    for i in range(H):
        if A[i][x] == '#':
            return False
    return True


ng_col = [i for i in range(H) if f1(i)]
ng_row = [i for i in range(W) if f2(i)]

for i in range(H):
    if i in ng_col:
        continue
    for j in range(W):
        if j in ng_row:
            continue
        print(A[i][j], end='')
    print()
