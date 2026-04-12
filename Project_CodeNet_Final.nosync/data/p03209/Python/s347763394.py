import sys
input = sys.stdin.readline

N,X=map(int,input().split())

num = [0]*N
pnum = [0]*N
num[0] = 1
pnum[0] = 1
for i in range(1,N):
    num[i] = 2*num[i-1]+3
    pnum[i] = 2*pnum[i-1]+1

position = [0]*(N+1)
position[N] = X
for i in reversed(range(1,N+1)):
    if num[i-1]+2 < position[i]:
        position[i-1] = position[i] -num[i-1]-2
    else:
        if position[i]-1 < 1: break
        position[i-1] = position[i]-1
        

dp = [0]*(N+1)
dp[0] = 1
for i in range(1,N+1):
    if position[i] == 0 or position[i] == 1: continue
    if position[i] < num[i-1]+2:
        dp[i] = dp[i-1]
    elif position[i] == num[i-1]+2:
        dp[i] = pnum[i-1] + 1
    else:
        dp[i] = dp[i-1] + pnum[i-1] + 1
#print(pnum)
#print(position)
print(dp[N])
    

