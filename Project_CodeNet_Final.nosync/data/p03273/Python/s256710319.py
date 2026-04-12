h, w = map(int, input().split())
board = [input() for _ in range(h)]
ansH = [False] * h
ansW = [False] * w
for i in range(h):
    for j in range(w):
        if(board[i][j] == '#'):
            ansH[i] = True
            ansW[j] = True

for i in range(h):
    if(ansH[i] == False):
        continue
    ans = ""
    for j in range(w):
        if(ansW[j]):
            ans += board[i][j]
    print(ans)