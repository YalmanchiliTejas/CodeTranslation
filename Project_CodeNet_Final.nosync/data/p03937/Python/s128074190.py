def dfs(cnt=0, y=0, x=0):
    if y == H-1 and x == W-1:
        if S == cnt+1:
            global naraba
            naraba = True
        return
    for dy, dx in [(1, 0), (0, 1)]:
        ny, nx = y+dy, x+dx
        if 0 <= ny < H and 0 <= nx < W and A[ny][nx] == "#" and not V[ny][nx]:
            V[ny][nx] = True
            dfs(cnt+1, ny, nx)
            V[ny][nx] = False


if __name__ == "__main__":
    H, W = map(int, input().split())
    A = [list(input()) for _ in range(H)]
    V = [[False]*W for _ in range(H)]
    S = 0
    for a in A:
        S += a.count("#")
    V[0][0] = True
    naraba = False
    dfs()
    if naraba:
        print("Possible")
    else:
        print("Impossible")
