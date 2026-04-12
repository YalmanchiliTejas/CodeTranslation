n=int(input())
l=list(map(int,input().split()))
x=0
ans=0
for i in range(n):
    if l[i]>=x:
        ans+=1
        x=l[i]
print(ans)