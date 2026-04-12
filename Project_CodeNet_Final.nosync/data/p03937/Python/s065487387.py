
H,W = map(int,input().split())

A = [[c=='#' for c in input()] for _ in range(H)]

dp = [[False]*W for _ in range(H)]

dp[0][0] = True
def solve():

    s = sum(sum(l) for l in A)
    if s != H+W-1:
        return False

    for d in range(1,H+W):
        if d < W:
            dp[0][d] = dp[0][d-1] and A[0][d]
        if d < H:
            dp[d][0] = dp[d-1][0] and A[d][0]
        for i in range(1,d):
            j = d-i
            if i >= H or j >= W:
                continue
            dp[i][j] = A[i][j] and (dp[i-1][j] or dp[i][j-1])

    return dp[-1][-1]

print('Possible' if solve() else 'Impossible')