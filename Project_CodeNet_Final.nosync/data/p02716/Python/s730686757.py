n = int(input())
s = list(map(int,input().split()))
ans = -1000000000000000
dp = [{} for _ in range(n)]
dp[0][1] = s[0]
dp[1][1] = s[1]
if n >= 3:
    dp[2][1] = s[2]
for i in range(n):
    for x in dp[i].keys():
        y = dp[i][x]
        if x == n//2:
            ans = max(ans,y)
        else:
            if (n-(i+2)+1)//2 >= n//2-(x+1) and i+2 <= n-1:
                if x+1 in dp[i+2].keys():
                    dp[i+2][x+1] = max(dp[i+2][x+1],dp[i][x] + s[i+2])
                else:
                    dp[i+2][x+1] = dp[i][x] + s[i+2]
            if (n-(i+3)+1)//2 >= n//2-(x+1) and i+3 <= n-1:
                if x+1 in dp[i+3].keys():
                    dp[i+3][x+1] = max(dp[i+3][x+1],dp[i][x] + s[i+3])
                else:
                    dp[i+3][x+1] = dp[i][x] + s[i+3]
            if (n-(i+4)+1)//2 >= n//2-(x+1) and i+4 <= n-1:
                if x+1 in dp[i+4].keys():
                    dp[i+4][x+1] = max(dp[i+4][x+1],dp[i][x]+s[i+4])
                else:
                    dp[i+4][x+1] = dp[i][x]+s[i+4]
print(ans)
