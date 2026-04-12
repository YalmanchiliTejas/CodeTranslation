import sys
input = sys.stdin.readline

n=int(input())
k=int(input())

dp1=[0]*(k+1)
dp2=[0]*(k+1)
dp1[0]=1

for x in map(int,str(n)):
    for j in range(k,-1,-1):
        if j>0:
            dp2[j]+=dp2[j-1]*9
            if x!=0:
                dp2[j]+=dp1[j-1]*(x-1)+dp1[j]
                dp1[j]=dp1[j-1]
            #print(dp1)
            #print(dp2)
        else:
            dp2[j]=1
            dp1[j]=0
print(dp1[k]+dp2[k])
