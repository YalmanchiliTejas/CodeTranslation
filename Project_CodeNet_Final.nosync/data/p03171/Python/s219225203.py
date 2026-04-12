N=int(input())
A=list(map(int,input().strip().split(' ')))
MAx=max(A)
dp=[[-3*max(A)]*N for i in range(N)]
for i in range(N):
    dp[i][i]=A[i]

for length in range(2,len(A)+1):
    for start in range(0,len(A)-length+1):
        left=start
        right=start+length-1
        temp1=0
        temp2=0
        dp[left][right]=max(A[left]-dp[left+1][right],A[right]-dp[left][right-1])
print(dp[0][-1])