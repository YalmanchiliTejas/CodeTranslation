N=int(input())
A=list(map(int,input().split()))

Asum=[0]
for i in A:
  Asum.append(Asum[-1]+i)

s=sum(A)
ans=0

for i,v in enumerate(A):
  ans+=v*(Asum[-1]-Asum[i+1])
  ans%=10**9+7

print(ans)