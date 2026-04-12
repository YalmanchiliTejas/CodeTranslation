def read():
    return [int(x) for x in str.split(raw_input())]

n, m = read()
st = []
cnt = 0

for i in range(n):
    st.append(raw_input())
    for j in range(m):
        if (st[i][j] == '#'):
            cnt = cnt+1
            
def can_down(st, x, y):
    return x+1 < n and st[x+1][y] == '#'

def can_right(st, x, y):
    return y+1 < m and st[x][y+1] == '#'

def dfs(st, x, y, c):
    if (x == n-1 and y == m-1):
        return c == cnt
    down, right = can_down(st, x, y), can_right(st, x, y)
    if (down and right):
        return 0
    if ((not down) and (not right)):
        return 0
    if (down):
        return dfs(st, x+1, y, c+1)
    if (right):
        return dfs(st, x, y+1, c+1)

if (dfs(st, 0, 0, 1) == 1):
    print("Possible")
else:
    print("Impossible");
