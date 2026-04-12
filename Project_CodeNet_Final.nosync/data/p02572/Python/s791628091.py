n=int(input())
a=list(map(int,input().split()))
ans=0
cum=[0]
for i in range(n):
    cum.append((cum[i]+a[i])%(10**9+7))
for i in range(n):
    # print(a[i],cum[-1]-cum[i+1])
    ans+=a[i]*(cum[-1]-cum[i+1])%(10**9+7)
    ans%=(10**9+7)
print(ans)