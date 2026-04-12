#intじゃ無理
K=str(input())
D=int(input())
N=len(K)
P=10**9+7


#DP[i][smaller][j]=上からi(1<=i<=len(K))桁目までで桁総和modDがj(0<=j<=D-1)の個数
DP=[[[0]*(D) for index1 in range(2)] for index2 in range(N+1)]
#i=0に関しては初期値として与える
DP[0][0][0]=1

#桁DP:O(ND)
for i in range(1,N+1):
    for j in range(D):
        for k in range(10):
            DP[i][1][(j+k)%D]=(DP[i][1][(j+k)%D]+DP[i-1][1][j])%P
        for l in range(int(K[i-1])):
            DP[i][1][(j+l)%D]=(DP[i][1][(j+l)%D]+DP[i-1][0][j])%P
        DP[i][0][(j+int(K[i-1]))%D]=(DP[i][0][(j+int(K[i-1]))%D]+DP[i-1][0][j])%P

#0を除く
print((DP[N][0][0]+DP[N][1][0]-1)%P)



