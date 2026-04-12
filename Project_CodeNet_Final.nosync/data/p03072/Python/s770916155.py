n=int(input())
H=list(map(int,input().split()))
now=H[0]
ans=0
for h in H:
    if now<=h:
        ans+=1
    now=max(now,h)
print(ans)