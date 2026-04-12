n=int(input())
h=list(map(int,input().split()))
tmp=h[0]
ans=0
for i in range(n):
    if tmp<=h[i]:
        ans+=1
        tmp=h[i]
print(ans)
