n = int(input())

lista = list(map(int,input().split()))

dp = [[0] * n for i in range(n)]

for i in range(n):
    dp[i][i] = lista[i]

for i in range(1,n):
    for j in range(i-1,-1,-1):
        dp[j][i] = max(lista[j] - dp[j+1][i], lista[i] - dp[j][i-1])

print(dp[0][n-1])
