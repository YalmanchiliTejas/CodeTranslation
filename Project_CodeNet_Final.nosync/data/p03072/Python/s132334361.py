n=int(input())
h=list(map(int,input().split()))

ans=1
for i in range(1,n):
    for j in range(i):
        can_see=True
        if h[i]<h[j]:
            can_see=False
            break
    if can_see: ans+=1

print(ans)

