n=input()
k=int(input())

dp0=[[0]*(k+2) for i in range(len(n)+1)]

dp1=[[0]*(k+2) for i in range(len(n)+1)]
dp1[0][0]=1
# i桁まで見て j個の１から９を使ってn以下確定したもの　dp0[i][j]
#                                  確定していないもの　dp1[i][j]
for i in range(len(n)):
    for j in range(k+1):
        x=int(n[i])
        if x!=0:
            # 0を立てる
            dp0[i+1][j]+=dp0[i][j]+dp1[i][j]
            # 0以外を立てる
            dp0[i+1][j+1]+=dp0[i][j]*9
            if dp1[i][j]!=0:
                dp0[i+1][j+1]+=x-dp1[i][j]
            dp1[i+1][j+1]+=dp1[i][j]
        else:
            # 0を立てる
            dp0[i+1][j]+=dp0[i][j]
            dp1[i+1][j]+=dp1[i][j]
            # 0以外を立てる
            dp0[i+1][j+1]+=dp0[i][j]*9

print(dp0[-1][-2]+dp1[-1][k])