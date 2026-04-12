n=int(input())
lst = list(map(int,input().split()))
maxv=lst[0]
ans=1
for i in range(1,n):
    if lst[i]>=maxv:
        ans+=1
        maxv=lst[i]
print(ans)