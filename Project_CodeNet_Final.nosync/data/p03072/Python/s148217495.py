N=int(input())
H=list(map(int,input().split()))
M=H[0]
ans=1
for i in range(1,N):
    if H[i]>=M:
        ans+=1
    M=max(M,H[i])
print(ans)