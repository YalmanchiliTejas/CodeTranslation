n=int(input())
l=list(map(int,input().split()))
m=0
ans=0
for i in l:
    if m<=i:
        m=i
        ans+=1
print(ans)