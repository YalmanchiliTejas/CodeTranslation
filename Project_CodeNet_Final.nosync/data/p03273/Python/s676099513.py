H, W = map(int, input().split())
Ass = [input() for _ in range(H)]

numHs = [0] * H
numWs = [0] * W
for i in range(H):
    for j in range(W):
        if Ass[i][j] == '#':
            numHs[i] += 1
            numWs[j] += 1

for i in range(H):
    if numHs[i] == 0: continue
    Bs = []
    for j in range(W):
        if numWs[j]:
            Bs += Ass[i][j]
    print(''.join(Bs))
