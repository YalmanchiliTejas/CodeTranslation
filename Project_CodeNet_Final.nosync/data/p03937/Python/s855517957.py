H, W = map(int, input().split())
G = [input() for i in range(H)]
done = [[False]*W for i in range(H)]
def dfs(h, w):
    done[h][w] = True
    if h == H-1 and w == W-1:
        return
    if w+1 < W and G[h][w+1] == "#":
        dfs(h, w+1)
    elif h+1 < H and G[h+1][w] == "#":
        dfs(h+1, w)
dfs(0, 0)
ans = True
for i in range(H):
    for j in range(W):
        if G[i][j] == "#":
            if not done[i][j]:
                ans = False
if ans:
    print("Possible")
else:
    print("Impossible")
