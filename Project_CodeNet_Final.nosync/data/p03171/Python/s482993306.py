n = int(input())
s = list(map(int,input().split()))
dp = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    if n%2 ==0:
        dp[i][i]=-s[i]
        turn =0
    else:
        dp[i][i]=s[i]
        turn = 1
def findMax(i,j):
    dp[i][j] = max(dp[i+1][j]+s[i],dp[i][j-1]+s[j])
def findMin(i,j):
    dp[i][j]= min(dp[i+1][j]-s[i],dp[i][j-1]-s[j])
for length in range(2,n+1):
    for j in range(n-length+1):
        if not turn:
            findMax(j,j+length-1)
        else:
            findMin(j,j+length-1)
    turn^=1

print(dp[0][n-1])

