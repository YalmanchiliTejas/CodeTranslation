N=int(input())
A=list(map(int,input().split()))

DP=[[-10**16 for i in range(N)]for j in range(3)]

DP[1][0]=0
DP[2][0]=0
DP[2][1]=0
DP[0][0]=A[0]
DP[1][1]=A[1]
if N>=3:
    DP[2][2]=A[2]

for i in range(2,N):
    DP[0][i]=DP[0][i-2]+A[i]
    DP[1][i]=DP[1][i-2]+A[i]
    DP[2][i]=DP[2][i-2]+A[i]
    if i-3>=0:
        DP[1][i]=max(DP[1][i],DP[0][i-3]+A[i])
        DP[2][i]=max(DP[2][i],DP[1][i-3]+A[i])
    if i-4>=0:
        DP[2][i]=max(DP[2][i],DP[0][i-4]+A[i])

if N%2==0:
    print(max(DP[0][-2],DP[1][-1]))
else:
    print(max(DP[0][-3],DP[1][-2],DP[2][-1]))