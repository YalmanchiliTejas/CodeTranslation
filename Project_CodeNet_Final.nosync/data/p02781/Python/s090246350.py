import numpy as np

N=int(input())
n=[int(i) for i in str(N)]
K=int(input())
L=len(n)
dp=np.zeros((L+1,K+1,2),dtype=int)
dp[0,0,0]=1

for i in range(L):
  for j in range(K+1):
    for smaller in range(2):
      m=10 if smaller else n[i]+1
      for x in range(m):
        if int(j+(x!=0))>K:
          continue
        #i桁目がxだったときにdp[i][smaller][j]をどこに足しますか？
        dp[i+1,j+(x!=0),smaller or x<n[i]]+=dp[i,j,smaller]
        #print(i+1,j+(x!=0),int(smaller or x<n[i]),i,j,smaller)
        
print(dp[L,K].sum())