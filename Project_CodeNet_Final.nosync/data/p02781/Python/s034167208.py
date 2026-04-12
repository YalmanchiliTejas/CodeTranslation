n=int(input())
k=int(input())

if n<10:
    if k==0:
        print(1)
    elif k==1:
        print(n)
    else:
        print(0)
    exit()

#10
#0の数は高々3つまでなので、jは0,1,2,3の配列だけ持てば良い
#i桁目までは高々100
#
#dp[i][j][smaller]=

lenn=len(str(n))

dp=[[[0]*2 for _ in range(4)]  for _ in range(lenn)]
#smallerは、0：:通常、1:未満の2パターン

if int(str(n)[0])==1:
    dp[0][0][0]=1
    dp[0][1][1]=1
else:
    dp[0][0][0]=1
    dp[0][1][0]=int(str(n)[0])-1
    dp[0][1][1]=1

#print(dp)

for i in range(lenn-1):
    dp[i+1][0][0]+=dp[i][0][0]
    dp[i+1][1][0]+=dp[i][0][0]*9+dp[i][1][0] #+dp[i][0][1]*max(0,(int(str(n)[i])-1))
    dp[i+1][2][0]+=dp[i][1][0]*9+dp[i][2][0] #+dp[i][1][1]*max(0,(int(str(n)[i])-1))
    dp[i+1][3][0]+=dp[i][2][0]*9+dp[i][3][0] #+dp[i][2][1]*max(0,(int(str(n)[i])-1))
    #print(dp)
    if int(str(n)[i+1])==0:
        dp[i+1][0][1]+=dp[i][0][1]
        dp[i+1][1][1]+=dp[i][1][1]
        dp[i+1][2][1]+=dp[i][2][1]
        dp[i+1][3][1]+=dp[i][3][1]

    elif int(str(n)[i+1])==1:
        dp[i+1][1][1]+=dp[i][0][1]
        dp[i+1][2][1]+=dp[i][1][1]
        dp[i+1][3][1]+=dp[i][2][1]

        dp[i+1][1][0]+=dp[i][1][1]
        dp[i+1][2][0]+=dp[i][2][1]
        dp[i+1][3][0]+=dp[i][3][1]
    else:
        dp[i+1][1][1]+=dp[i][0][1]
        dp[i+1][2][1]+=dp[i][1][1]
        dp[i+1][3][1]+=dp[i][2][1]

        dp[i+1][1][0]+=dp[i][1][1]
        dp[i+1][2][0]+=dp[i][2][1]
        dp[i+1][3][0]+=dp[i][3][1]

        dp[i+1][1][0]+=dp[i][0][1]*(int(str(n)[i+1])-1)
        dp[i+1][2][0]+=dp[i][1][1]*(int(str(n)[i+1])-1)
        dp[i+1][3][0]+=dp[i][2][1]*(int(str(n)[i+1])-1)
    #print(dp)

print(sum(dp[-1][k]))