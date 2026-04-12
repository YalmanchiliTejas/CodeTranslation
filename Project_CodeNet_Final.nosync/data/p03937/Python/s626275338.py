H, W = [int(i) for i in input().split()]
A = [list(input()) for _ in range(H)]

def dfs(h, w, count):
    if (h, w) == (H - 1, W - 1):
        return count

    ans = 0
    for nh, nw in [(h + 1, w), (h, w + 1)]:
        if 0 <= nh < H and 0 <= nw < W and A[nh][nw] == "#":
            ans += dfs(nh, nw, count + 1)
    return ans

if dfs(0, 0, 1) == sum(a.count("#") for a in A):
    print("Possible")
else:
    print("Impossible")
