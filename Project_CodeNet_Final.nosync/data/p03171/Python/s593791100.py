N=int(input())
A=list(map(int,input().split()))

#DP[i][j]=A[i]からA[j-1]まで残っていた時のX-Yの予測値(0<=i<=j<=N,i=jならばDP=0)
DP=[[0]*(N+1) for _ in range(N+1)]

#j-i=1から初めてi=0かつj=Nまで、すなわちj-i=Nまで考える
for len in range(1,N+1):
    for i in range(0,N): #0<=i<Nで考えれば良い、というかi<=N-lenで良い
        j=i+len #正直len=1は例外的、maxもminもないが気にしない
        if j<=N:
            if (N-len)%2==0:#先手
                DP[i][j]=max(A[i]+DP[i+1][j],A[j-1]+DP[i][j-1])
            else:#後手
                DP[i][j]=min(-A[i]+DP[i+1][j],-A[j-1]+DP[i][j-1])
        else:
            break

#for index1 in range(N+1):
    #string=''
    #for index2 in range(N+1):
        #string+=str(DP[index1][index2])+' '
    #print(string)

print(DP[0][N])




