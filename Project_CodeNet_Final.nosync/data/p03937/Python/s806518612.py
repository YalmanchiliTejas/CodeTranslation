H, W = map(int, input().split())
Ass = ['.#' + '.' * W] + ['.' + input() + '.' for _ in range(H)] + ['.' * W + '#.']

def solve():
    for x in range(1, H + 1):
        for y in range(1, W + 1):
            if Ass[x][y] == '.': continue
            isOK_pX = Ass[x - 1][y] == '#'
            isOK_pY = Ass[x][y - 1] == '#'
            isOK_nX = Ass[x + 1][y] == '#'
            isOK_nY = Ass[x][y + 1] == '#'
            if isOK_pX == isOK_pY or isOK_nX == isOK_nY:
                print('Impossible')
                return
    print('Possible')

solve()
