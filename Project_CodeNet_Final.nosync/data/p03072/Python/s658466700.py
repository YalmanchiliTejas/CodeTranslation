N=int(input())
H=list(map(int,input().split()))
Hmax=0


ans=0
for i in range(N):
    if H[i]>=Hmax:
        ans+=1
        Hmax=H[i]
        
print(ans)