N=int(input())
L=list(map(int,input().split()))

Hmax=L[0]
ans=0

for i in range(N):
    if L[i]>=Hmax:
        Hmax=L[i]
        ans+=1

print(ans)