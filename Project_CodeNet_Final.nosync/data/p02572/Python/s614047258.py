n=int(input())
arr=list(map(int,input().split()))
s=sum(arr)
ans=0
m=10**9+7
c=0
for i in arr:
    c+=i
    ans+=i*(s-c)
    ans%=m
print(ans)