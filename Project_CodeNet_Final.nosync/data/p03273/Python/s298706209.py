H, W = map(int, input().split())
L = []
for i in range(H):
    L.append(list(input()))
dH = []
for i in range(H):
    if L[i].count('.') == W:
        dH.append(i)
dW = []
for i in range(W):
    flag = True
    for j in range(H):
        if L[j][i] == '#':
            flag = False
            break
    if flag:
        dW.append(i)
for i in range(H):
    if i in dH:
        continue
    ans = []
    for j in range(W):
        if not j in dW:
            ans.append(L[i][j])
    print(''.join(ans))