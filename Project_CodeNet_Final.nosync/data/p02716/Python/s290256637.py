INF=float('inf')
def solve1():
    dp=[[-INF]*2 for i in range(N+1)]
    dp[0][0]=0;dp[1][0]=A[0];dp[2][1]=A[1]
    for i in range(N):
        if dp[i+1][0]==-INF:
            if i-1>=0:
                dp[i+1][0]=max(dp[i+1][0],dp[i-1][0]+A[i])
        if dp[i+1][1]==-INF:
            if i-1>=0:
                dp[i+1][1]=max(dp[i+1][1],dp[i-1][1]+A[i])
            if i-2>=0:
                dp[i+1][1]=max(dp[i+1][1],dp[i-2][0]+A[i])
    print(max(dp[N][1],dp[N-1][0]))
    return
def solve2():
    dp=[[-INF]*3 for i in range(N+1)]
    dp[0][0]=0;dp[1][0]=A[0];dp[2][1]=A[1];dp[3][2]=A[2]
    for i in range(N):
        if dp[i+1][0]==-INF:
            if i-1>=0:
                dp[i+1][0]=max(dp[i+1][0],dp[i-1][0]+A[i])
        if dp[i+1][1]==-INF:
            if i-1>=0:
                dp[i+1][1]=max(dp[i+1][1],dp[i-1][1]+A[i])
            if i-2>=0:
                dp[i+1][1]=max(dp[i+1][1],dp[i-2][0]+A[i])
        if dp[i+1][2]==-INF:
            if i-1>=0:
                dp[i+1][2]=max(dp[i+1][2],dp[i-1][2]+A[i])
            if i-2>=0:
                dp[i+1][2]=max(dp[i+1][2],dp[i-2][1]+A[i])
            if i-3>=0:
                dp[i+1][2]=max(dp[i+1][2],dp[i-3][0]+A[i])
    print(max(dp[N][2],dp[N-1][1],dp[N-2][0]))
    return

N=int(input())
A=list(map(int,input().split()))

if N%2==0:
    solve1()
else:
    solve2()