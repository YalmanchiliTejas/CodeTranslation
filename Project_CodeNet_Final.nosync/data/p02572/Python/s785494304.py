n=int(input())
a=list(map(int,input().split()))
su=sum(a)
ru=[0 for i in range(n)]
ru[0]=su-a[0]

for i in range(1,n):
    ru[i]=ru[i-1]-a[i]
ans=0
for i in range(0,n-1):
    ans+=(a[i]*(ru[i]%1000000007))%1000000007
    ans=ans%1000000007
print(ans)