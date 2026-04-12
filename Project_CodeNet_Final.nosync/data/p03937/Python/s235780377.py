H, W = map(int, input().split())

A = [list(input()) for _ in range(H)]
length = 0
for a in A:
    for s in a:
        if s == '#':
            length += 1


def dfs(i, j, cnt):
    if i == H - 1 and j == W - 1:
        return cnt == length - 1
    else:
        if i < H - 1 and A[i + 1][j] == '#':
            return dfs(i + 1, j, cnt + 1)
        elif j < W - 1 and A[i][j + 1] == '#':
            return dfs(i, j + 1, cnt + 1)
        else:
            return False


print('Possible' if dfs(0, 0, 0) else 'Impossible')
