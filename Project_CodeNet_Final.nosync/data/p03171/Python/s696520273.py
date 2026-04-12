n = int(input())
lst = list(map(int, input().split()))

ans = 0

dp = [[0] * (n+1) for _ in range(n+1)] #dp[i]は石の数が残りi個のときに手番プレイヤーが勝利できるか

for i in range(n+1):
    for j in range(n - i+1):
        l = j
        r = j+i
        if l-r== 0:
            dp[l][r] == 0
        elif (n - (l - r-1)) % 2  ==1:
            dp[l][r] =  max(dp[l+1][r] + lst[l], dp[l][r-1] + lst[r-1])
        else:
            dp[l][r] =  min(dp[l+1][r] -  lst[l], dp[l][r-1] -  lst[r-1])
           
ans = dp[0][n]            
print(ans)