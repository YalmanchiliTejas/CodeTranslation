h, w = map(int, input().split())
A = [list(input()) for i in range(h)]


def dfs(x, y):
    A[x][y] = '.'

    if x == h-1 and y == w-1:
        return
    elif x+1 < h and A[x+1][y] == '#':
        dfs(x+1, y)
    elif y+1 < w and A[x][y+1] == '#':
        dfs(x, y+1)
    else:
        return


dfs(0, 0)
if A == [['.'] * w] * h:
    print('Possible')
else:
    print('Impossible')