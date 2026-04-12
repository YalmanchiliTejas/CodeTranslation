n=int(input())
m=0
ans=0
for i in input().split():
    if int(i)>=m:
        ans+=1
        m=int(i)

print(ans)