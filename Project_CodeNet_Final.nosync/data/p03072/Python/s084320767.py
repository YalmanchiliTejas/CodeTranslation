n=int(input())
h=list(map(int,input().split()))
hi=h[0]
ans=1
for i in range(1,n):
    if hi<=h[i]:
        ans+=1
        hi=h[i]
print(ans)