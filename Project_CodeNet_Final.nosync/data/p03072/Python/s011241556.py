N=int(input())
H=list(map(int,input().split()))
m=0
ans=0
for h in H:
    if h>=m:
        ans+=1
        m=h
print(ans)