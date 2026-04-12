n=int(input())
h=list(map(int,input().split()))
ans=0
tmp=h[0]
for i in range(len(h)):
    if tmp<=h[i]:
        ans+=1
        tmp=h[i]
print(ans)