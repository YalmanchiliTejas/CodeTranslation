n=int(input())
h=list(map(int,input().split()))
hm=0
ans=0

for i in range(n):
    if(hm<=h[i]):
        ans+=1
        hm=h[i]

print(ans)
