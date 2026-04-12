# coding: utf-8
# Your code here!
N=input()
K=int(input())
#Nは最大で100桁あるので、整数では扱いにくい
#そこでstringで入力する

#桁DPの典型的な問題
#まず、Nの具体的な値は無視して、以下のDPをする
#dp[i][j][k]=[j*10^i,(j+1)*10^i)までに0でない桁がk桁あるような数の個数
#このDPは、以下の遷移で求まる
#dp[i][j][k]=(i=0 j=0 k=0)1
#            (i=0 j=0 k!=0)0
#            (i=0 j!=0 k=1)1
#            (i=0 j!=0 k!=1)0
#            (i!=0 j=0)Σ[j,0~9] dp[i-1][j][k]
#            (i!=0 j!=0)Σ[j,0~9] dp[i-1][j][k-1]

dp = [[[0 for i in range(5)] for j in range(11)] for k in range(104)]
for j in range(10):
    if j==0:
        dp[0][j][0]=1
    else:
        dp[0][j][1]=1

for k in range(K+1):
    for i in range(len(N)):
        if i==0:
            continue
        for j in range(10):
            if j==0:
                for l in range(10):
                    dp[i][j][k]+=dp[i-1][l][k]
            elif (k != 0):
                for l in range(10):
                    dp[i][j][k]+=dp[i-1][l][k-1]


#そうしてDPのボードが完成したら答えを求める
#Nの上からi桁目をDとおき、[0,D)だけdp[i][j][k]を足す
#なお、最後の桁だけは[0,D]
#Dが0のときは以降の桁に0が残り続けるので、kをデクリメントする
#全ての桁を調べるかkが負になったら終了

Ans=0
k=K
for i in range(len(N)):
    D=int(N[i])
    if i==len(N)-1:
        D+=1
    for j in range(D):
        Ans+=dp[len(N)-i-1][j][k]
    if D!=0:
        k-=1
    if k<0:
        break

print(Ans)


