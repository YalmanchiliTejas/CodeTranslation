N=int(input())
A=list(map(int,input().split()))
if N==2:
    print(max(A))
elif N==3:
    print(max(A))
else:
    if N%2==1:
        dp=[[0 for i in range(0,3)] for i in range(0,N)]
        dp[0][2]=A[0]
        dp[0][1]=-float('inf')
        dp[0][0]=-float('inf')
        dp[1][2]=-float('inf')
        dp[1][1]=A[0]
        dp[1][0]=-float('inf')

        for i in range(2,N):
            if i==N-1:
                dp[N-1][0]=dp[N-3][0]+A[N-1]
            else:
                dp[i][0]=max(dp[i-2][0]+A[i],dp[i-1][1])
                dp[i][1]=max(dp[i-2][1]+A[i],dp[i-1][2])
                dp[i][2]=dp[i-2][2]+A[i]

        test1=dp[N-1][0]

        dp=[[0 for i in range(0,2)] for i in range(0,N)]
        dp[0][1]=-float('inf')
        dp[0][0]=0
        dp[1][1]=A[1]
        dp[1][0]=-float('inf')

        for i in range(2,N):
            if i==N-1:
                dp[N-1][0]=dp[N-3][0]+A[N-1]
            else:
                dp[i][0]=max(dp[i-2][0]+A[i],dp[i-1][1])
                dp[i][1]=dp[i-2][1]+A[i]

        test2=dp[N-1][0]

        A=A[::-1]
        dp=[[0 for i in range(0,2)] for i in range(0,N)]
        dp[0][1]=-float('inf')
        dp[0][0]=0
        dp[1][1]=A[1]
        dp[1][0]=-float('inf')

        for i in range(2,N):
            if i==N-1:
                dp[N-1][0]=dp[N-3][0]+A[N-1]
            else:
                dp[i][0]=max(dp[i-2][0]+A[i],dp[i-1][1])
                dp[i][1]=dp[i-2][1]+A[i]

        test3=dp[N-1][0]

        test4=sum(A[i] for i in range(0,N) if i%2==1)

        print(max(test1,test2,test3,test4))

    if N%2==0:
        dp=[[0 for i in range(0,2)] for i in range(0,N)]
        dp[0][1]=A[0]
        dp[0][0]=-float('inf')
        dp[1][1]=-float('inf')
        dp[1][0]=A[0]

        for i in range(2,N):
            if i==N-1:
                dp[N-1][0]=dp[N-3][0]+A[N-1]
            else:
                dp[i][0]=max(dp[i-2][0]+A[i],dp[i-1][1])
                dp[i][1]=dp[i-2][1]+A[i]

        test1=dp[N-1][0]

        test3=sum(A[i] for i in range(0,N) if i%2==0)
        test4=sum(A[i] for i in range(0,N) if i%2==1)

        print(max(test1,test3,test4))