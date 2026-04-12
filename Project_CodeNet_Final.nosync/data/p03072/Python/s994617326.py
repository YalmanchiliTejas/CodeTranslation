n=int(input())
hl=list(map(int,input().split()))
mx=0
mxh=[]
ans=1
for i in range(n):
    mx=max(mx,hl[i])
    mxh.append(mx)
for i in range(1,n):
    if hl[i]>=mxh[i-1]:
        ans+=1
print(ans)