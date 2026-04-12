n=int(input())
i = list(map(int, input().split())) 

m=sum(i)

ans=0
for k in range(n):
    ans+=(i[k]*(m-i[k]))
ans=ans//2
ans=ans%(10**9+7)
print(ans)