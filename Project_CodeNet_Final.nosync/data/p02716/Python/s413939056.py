N=int(input())
A=list(map(int,input().split()))
if N%2==0:
    dp=[[-float("inf") for _ in range(2)] for _ in range(N+10)]
    if N==2:
        print(max(A[0],A[1]))
    else:
        for i in range(N):
            if i==0:
                dp[i][0]=A[0]
            elif i==1:
                dp[i][1]=A[1]
            elif i==2:
                dp[i][0]=A[0]+A[2]
            else:
                for j in range(2):
                    if j==0:
                        dp[i][0]=max(dp[i][0],dp[i-2][0]+A[i])
                    elif j==1:
                        dp[i][1]=max(dp[i][1],dp[i-2][1]+A[i],dp[i-3][0]+A[i])
        print(max(dp[N-1]))
else:
    #print(A[0],A[1])
    dp=[[-float("inf") for _ in range(3)] for _ in range(N+10)]
    if N==3:
        print(max(A[0],A[1],A[2]))
    else:
        for i in range(N):
            if i<4:
                if i==0:
                    dp[i][0]=A[0]
                if i==1:
                    dp[i][1]=A[1]
                if i==2:
                    dp[i][2]=A[2]
                    dp[i][0]=A[0]+A[2]
                if i==3:
                    dp[i][1]=max(dp[1][1]+A[3],dp[0][0]+A[3])
            else:
                for j in range(3):
                    if j==0:#ここでも2こずつ規則よく飛ばすと決めた
                        dp[i][0]=max(dp[i][0],dp[i-2][0]+A[i])
                    elif j==1:#1回だけ無茶した
                        dp[i][1]=max(dp[i][1],dp[i-2][1]+A[i],dp[i-3][0]+A[i])
                    else:
                        dp[i][2]=max(dp[i][2],dp[i-2][2]+A[i],dp[i-3][1]+A[i],dp[i-4][0]+A[i])
        print(max(dp[N-1]))