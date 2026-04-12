N=int(input())
H=[0]+[int(x) for x in input().split()]
ans=0
for i in range(1,N+1):
    if H[i-1]<=H[i]:
        ans+=1
    H[i]=max(H[i],H[i-1])
print(ans)