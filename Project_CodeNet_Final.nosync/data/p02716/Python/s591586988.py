# coding: utf-8
# Your code here!
N=int(input())

A=list(map(int,input().split()))

if N==2:
    print(max(0,A[0],A[1]))
    exit()
if N==3:
    print(max(0,A[0],A[1],A[2]))
    exit()

dp=[[-10**18 for i in range(N)] for j in range(3)]
dp[0][0]=A[0]
dp[1][1]=A[1]
dp[2][2]=A[2]

for n in range(3):
    for index in range(N):
        if dp[n][index]!=-1:
            if n!=2 and index+3<N:
                dp[n+1][index+3]=max(dp[n+1][index+3],dp[n][index]+A[index+3])
            if n==0 and index+4<N:
                dp[n+2][index+4]=max(dp[n+2][index+4],dp[n][index]+A[index+4])
            if index+2<N:
                dp[n][index+2]=max(dp[n][index+2],dp[n][index]+A[index+2])

a=(dp[0][-1])
b=(dp[1][-1])
c=(dp[2][-1])

print(max(a,b,c))


        
