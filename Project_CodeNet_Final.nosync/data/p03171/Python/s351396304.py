# dp[j][i]=(区間[i,j]が残っているとき次の手番の得点-そうじゃない人の得点)
import sys
sys.setrecursionlimit(1000000000)
input = sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
INF=-10**14
dp=[[0]*(i+1) for i in range(n)]
for i in range(n):
    dp[i][i]=a[i]
for i in range(1,n):
    for j in range(i-1,-1,-1):
        dp[i][j]=max(a[i]-dp[i-1][j],a[j]-dp[i][j+1])
print(dp[-1][0])