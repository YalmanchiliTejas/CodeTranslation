h,w=map(int,raw_input().split())
a=[map(int,raw_input().split()) for _ in xrange(h)]
dp=[[[0]*(h+1) for _ in xrange(w+1)] for _ in xrange(h+1)]

for i in xrange(h):
    for j in xrange(w):
        for k in xrange(h):
            if i+j-k<=-1 or i+j-k>=w:
                continue
            if i==k:
                dp[i+1][j+1][k+1]=max(dp[i][j+1][k+1],dp[i+1][j][k+1],dp[i][j+1][k],dp[i+1][j][k])+a[i][j]
            else:
                dp[i+1][j+1][k+1]=max(dp[i][j+1][k+1],dp[i+1][j][k+1],dp[i][j+1][k],dp[i+1][j][k])+a[i][j]+a[k][i+j-k]

print(dp[h][w][h])