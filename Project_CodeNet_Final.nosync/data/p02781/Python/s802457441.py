N=int(input())
K=int(input())
dp1=[[0 for _ in range(4)] for _ in range(101)]
dp2=[[0 for _ in range(4)] for _ in range(101)]
dp1[0][0]=1
for i in range(1, 101):
    dp1[i][0]=1
    for j in range(1, 4):
        dp1[i][j]=dp1[i-1][j-1]*9+dp1[i-1][j]
dp2[0][1]=1
for i in range(1, 101):
    dp2[i][1]=dp1[i][1]+1
    dp2[i][2]=dp1[i][2]
    dp2[i][3]=dp1[i][3]
ans=0
i=len(str(N))-1
cnt=0
while i>=0:
    k=int(str(N)[len(str(N))-1-i])
    if k==0:
        i-=1
        continue
    ans+=dp2[i][K-cnt]
    cnt+=1
    if K-cnt<0:
        break
    ans+=dp1[i][K-cnt]*(k-1)
    i-=1
print(ans)
