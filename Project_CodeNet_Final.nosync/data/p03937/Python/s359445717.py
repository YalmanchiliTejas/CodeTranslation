H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

i = j = 0

visited = [[None] * W for _ in range(H)]

def dp(i, j):
    global H, W
    visited[i][j] = True
    if i == H - 1 and j == W - 1: return True
    #
    if i + 1 >= H:
        d = False
    else:
        d = (A[i + 1][j] == '#')
    #
    if j + 1 >= W:
        r = False
    else:
        r = (A[i][j + 1] == '#')
    #
    if d and not r:
        return dp(i + 1, j)
    elif not d and r:
        return dp(i, j + 1)
    else:
        return False

if dp(0, 0):
    ans = 'Possible'
    for i in range(H):
        for j in range(W):
            if not visited[i][j] and A[i][j] == '#':
                ans = 'Impossible'
    #
    print(ans)
else:
    print('Impossible')