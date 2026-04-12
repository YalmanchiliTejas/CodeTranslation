H, W = map(int, input().split())
A = [list(input()) for i in range(H)]
hi_list = []
wj_list = []
for i in range(H):
    c = 0
    for j in range(W):
        if A[i][j] == '.':
            c += 1
    if c == W:
        hi_list += [i]
for j in range(W):
    c = 0
    for i in range(H):
        if A[i][j] == '.':
            c += 1
    if c == H:
        wj_list += [j]

hi_set = set(hi_list)
wj_set = set(wj_list)
for i in range(H):
    if i in hi_set:
        continue
    for j in range(W):
        if j in wj_set:
            continue
        print(A[i][j], end='')
    print()
