N=input()
K=int(input())
L=len(N)+1
dp=[[[0]*L for _ in range(4)] for _ in range(2)]
dp[0][0][0]=1
for l in range(1,L):
    dp[1][0][l]=1

# まずNをもとにdp[0]を処理する
cnt=0
for l in range(1,L):
    if int(N[l-1])!=0:
        cnt+=1
    if cnt>3:
        break
    else:
        dp[0][cnt][l]=1


# 次にdp[1]を処理。
# 遷移としては
# dp[1][j-1][i-1]からdp[1][j][i]へは'1'から'9'が選ばれ*9
# dp[1][j][i-1]からdp[1][j][i]へは'0'が選ばれ*1
#以下、N[i-1]!=0の条件付き
# dp[0][j][i-1]からdp[1][j][i]へは'0'が選ばれ*1
# dp[0][j-1][i-1]からdp[1][j][i]へは'N[i-1]-1'までが選ばれ*(N[i-1]-1)

for i in range(1,L):
    for j in range(1,4):
        dp[1][j][i]+=dp[1][j-1][i-1]*9
        dp[1][j][i]+=dp[1][j][i-1]
        if int(N[i-1])>0:
            dp[1][j][i]+=dp[0][j][i-1]
            dp[1][j][i]+=dp[0][j-1][i-1]*(int(N[i-1])-1)
            

print(dp[0][K][L-1]+dp[1][K][L-1])