N=int(input())
H=list(map(int,input().split()))
ans=0
hmax=0
for i in range(N):
    if hmax<=H[i]:
        ans+=1
        hmax=H[i]
print(ans)