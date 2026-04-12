n=int(input())
a=list(map(int,input().split()))
ans=1
mx=a[0]
for i in a[1:]:
    if i>=mx:
        mx=i
        ans+=1
print(ans)