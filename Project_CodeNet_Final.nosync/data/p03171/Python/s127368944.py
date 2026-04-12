import sys
input=sys.stdin.readline
n=int(input())
A=tuple(map(int,input().split()))
DP=[[0]*(n+1) for _ in range(n+1)]
for j in range(1,n+1):
    for i in range(n-j+1):
        DP[j][i]=max(A[i]-DP[j-1][i+1],A[i+j-1]-DP[j-1][i])
print(DP[n][0])