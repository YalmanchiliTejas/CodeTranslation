# 次のダメパターンがあればImpossibleそれ以外はPossible
#  .#    ##
#  ## or #.

h, w = map(int, input().split())

table = []
for _ in range(h):
    a = input()
    temp = []
    for c in a:
        temp.append(c == '#')
    table.append(temp)

def check():
    for s in table:
        if True in s:
            return False
    return True
    
def solve(y, x):
    if table[y][x] == False:
        return False
    table[y][x] = False
    ret = False
    if y == h - 1 and x == w - 1:
        ret = check()
    else:
        if y < h - 1:
            ret = ret or solve(y + 1, x)
        if x < w - 1:
            ret = ret or solve(y, x + 1)
    table[y][x] = True
    return ret

ans = 'Possible' if solve(0, 0) else 'Impossible'

print(ans)