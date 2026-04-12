def dfs(s):
    global ans
    for u in v:
        x = s[0] + u[0]
        y = s[1] + u[1]
        if x < h and y < w:
            b[x][y] = "#"
            dfs([x, y])
            b[x][y] = "."
    if a == b:
        ans = 1
    return

h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
v = [[1, 0], [0, 1]]
b = [["."] * w for _ in range(h)]
b[0][0] = "#"
s = [0, 0]
ans = 0
dfs(s)
print("Possible" if ans == 1 else "Impossible")