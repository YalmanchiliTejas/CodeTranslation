n=int(input())
h=list(map(int,input().split()))
ans=1
for i in range(1,n):
    cnt=0
    for k in range(i):
        if h[i]>=h[k]:
            cnt+=1
    if cnt==i:
        ans+=1
print(ans)
