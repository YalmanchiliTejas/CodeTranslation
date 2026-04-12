n="0"+input()
x=len(n)
k=int(input())
l=[int(i) for i in n]

## dp1:top   dp2:under
dp1=[[0]*(k+2) for i in range(x)]
dp2=[[0]*(k+2) for i in range(x)]

dp1[0][0]=1
dp1[0][1]=0
dp2[0][0]=0
dp2[0][1]=0

cnt=0
for i in range(1,x):
    if l[i]>0:
        cnt+=1
    if cnt<=k:
        dp1[i][cnt]=1
for i in range(1,x):
    for j in range(k+1):
        if j==0:
            dp2[i][0]=1
        else:
            if l[i]==0: dp2[i][j]=(dp2[i-1][j-1]*9)+(dp2[i-1][j])+(dp1[i-1][j-1]*max(0,l[i]-1))
            else: dp2[i][j]=(dp2[i-1][j-1]*9)+(dp2[i-1][j])+(dp1[i-1][j-1]*max(0,l[i]-1))+(dp1[i-1][j])
print(dp1[-1][-2]+dp2[-1][-2])
