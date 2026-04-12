n=int(input())
l=list(map(int,input().split()))
ans=1
m=l[0]
for i in range(1,n):
    if m<=l[i]:
        m=l[i]
        ans+=1
print(ans)
    