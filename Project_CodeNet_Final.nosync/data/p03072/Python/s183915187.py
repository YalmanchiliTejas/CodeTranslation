N=int(input())
H=list(map(int,input().split()))
ans=0
hi=0

for i in range(N):
    if hi<=H[i]:
        ans+=1
    hi=max(hi,H[i])
print(ans)
