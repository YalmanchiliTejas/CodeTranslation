H, W = [int(_) for _ in input().split()]
A = [[_ for _ in input()] for _ in range(H)]


def parse(x, y):
    A[x][y] = '.'
    cand_OK = []
    cand_NG = []
    if x < H - 1:
        cand_OK += [[x + 1, y]]
    if y < W - 1:
        cand_OK += [[x, y + 1]]
    if x > 0:
        cand_NG += [[x - 1, y]]
    if y > 0:
        cand_NG += [[x, y - 1]]
    if any([A[i][j] == '#' for i, j in cand_NG]):
        return False
    if sum([A[i][j] == '#' for i, j in cand_OK]) == 2:
        return False
    if sum([A[i][j] == '.' for i, j in cand_OK]) == 2:
        return False
    if x == H - 1 and y == W - 1:
        return True
    for i, j in cand_OK:
        if A[i][j] == '#':
            return parse(i, j)


if parse(0, 0):
    print('Possible')
else:
    print('Impossible')
