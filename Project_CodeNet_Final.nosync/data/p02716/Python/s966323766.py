n = int(input())
ai = [int(i) for i in input().split()]

is_odd = True

if n % 2 == 0:
    is_odd = False

if is_odd == True:
    dp = [[0 for i in range(3)] for j in range(n)]
else:
    dp = [[0 for i in range(2)] for j in range(n)]

if n == 3:
    print(max(ai[0],ai[2],ai[1]))
    exit()
elif n == 2:
    print(max(ai[0],ai[1]))
    exit()
    

if is_odd == True:
    dp[0][0] = ai[0]
    dp[1][1] = ai[1]
    dp[2][0] = ai[0]+ai[2]
    dp[2][2] = ai[2]
    dp[3][1] = max(ai[0]+ai[3],ai[1]+ai[3])    
    for i in range(4,n):
        dp[i][0] = dp[i-2][0]+ai[i]
        dp[i][1] = max(dp[i-2][1]+ai[i],dp[i-3][0]+ai[i])
        dp[i][2] = max(dp[i-4][0]+ai[i],dp[i-3][1]+ai[i],dp[i-2][2]+ai[i])
    print(max(dp[n-3][0],dp[n-2][1],dp[n-1][2]))
else:
    dp[0][0] = ai[0]
    dp[1][1] = ai[1]
    dp[2][0] = ai[0]+ai[2]       
    for i in range(n):
        dp[i][0] = dp[i-2][0]+ai[i]
        dp[i][1] = max(dp[i-2][1]+ai[i],dp[i-3][0]+ai[i])
    print(max(dp[n-2][0],dp[n-1][1]))

