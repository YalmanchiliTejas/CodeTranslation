h, w = map(int, raw_input().split())
s = [list(raw_input().strip()) for _ in xrange(h)]
def dfs(x, y):
    if x == w - 1 and y == h - 1:
        s[y][x] = '.'
        return 1
    if x < w - 1 and s[y][x+1] == '#' and dfs(x + 1, y):
        s[y][x] = '.'
        return 1
    if y < h - 1 and s[y+1][x] == '#' and dfs(x, y + 1):
        s[y][x] = '.'
        return 1
    return 0
if dfs(0, 0) and sum(''.join(r).count('#') for r in s) == 0:
    print "Possible"
else:
    print "Impossible"
