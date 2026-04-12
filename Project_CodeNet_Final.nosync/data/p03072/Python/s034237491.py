n=int(input())
h=list(map(int,input().split()))
m=h[0]
ans=1
for i in range(1,n):
    if m<=h[i]:
        ans+=1
        m=h[i]
print(ans)
