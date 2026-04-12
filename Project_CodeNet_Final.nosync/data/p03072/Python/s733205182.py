N=int(input())
H=list(map(int,input().split()))

Hmax=H[0]
ans=0
for i in range(N):
    if H[i]>=Hmax:
        Hmax=H[i]
        ans+=1
print(ans)