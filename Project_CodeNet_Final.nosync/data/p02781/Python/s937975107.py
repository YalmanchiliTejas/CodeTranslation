
import numpy as np

N=input()
K=input()
dp=np.zeros((len(str(N))+10,len(str(N))+10,2))
dp=dp.tolist()


x0=int(N[0])
dp[0][0][0]=1


for i in range(0,len(N),1):
    for j in range(0,4,1):
        for k in range(0,2,1):
            nd=int(N[i])
            for d in range(0,10,1):
                ni=i+1
                nj=j
                nk=k
                if not(d==0):
                    nj=nj+1
                if ((k==0)and(d<nd)):
                    nk=1
                if (not(nj>int(K)))and(not((k==0)and(d>nd))):
                    dp[ni][nj][nk]=dp[ni][nj][nk]+dp[i][j][k]


print(int(dp[len(N)][int(K)][0]+dp[len(N)][int(K)][1]))
