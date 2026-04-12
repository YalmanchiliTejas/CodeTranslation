n=int(input())
l=list(map(int,input().split()))

m=l[0]
ans=0
for x in l:
    if m<=x:
        ans+=1
        m=x
print(ans)