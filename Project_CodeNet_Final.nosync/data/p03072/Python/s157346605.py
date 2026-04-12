n=int(input())
h=list(map(int, input().split()))
ans=1
for i in range(1,n):
    s=False
    for j in range(i):
        if h[i]>=h[j]:
            s=True
        else:
            s=False
            break
    if s==True:
        ans+=1
print(ans)