n=int(input())
h=list(map(int,input().split()))
takai=h[0]
ans=1
for i in range(1,n):
    if takai<=h[i]:
        takai=h[i]
        ans+=1
print(ans)