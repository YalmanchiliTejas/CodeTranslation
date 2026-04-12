h, w = map(int, input().split())
l = []
for i in range(h):
    l.append(list(input()) + ["."])
l[-1][w-1] = "g"
l.append(["."]*(w+1))

def dfs(x, y):
    if x == w or y == h or l[y][x] == ".":
        return
    elif l[y][x] == "g":
        print("Possible")
        exit()
    else:
        dfs(x+1, y)
        dfs(x, y+1)

cnt = 0
for i in l:
    for j in i:
        if j == "#":
            cnt += 1

if cnt == h + w - 2:
    dfs(0, 0)
print("Impossible")