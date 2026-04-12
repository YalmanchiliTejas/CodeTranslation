n=int(input())
ans=0
mountains=list(map(int,input().split()))
mx=mountains[0]
for i in mountains:
    if i>=mx:
        ans+=1
        mx=max(mx,i)
print(ans)