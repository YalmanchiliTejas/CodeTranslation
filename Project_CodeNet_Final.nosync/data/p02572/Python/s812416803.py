N=int(input())
a= list(map(int, input().split()))
s=[0]*N
s[0]=a[0]
for i in range(1,N):
    s[i]=s[i-1]+a[i]
#print(s)
kake=0
ans=0
sum=0
anskai=0
for i in range(N):
    kake=s[N-1]-s[i]
    ans=a[i]*kake
    sum+=ans
anskai=sum%(10**9+7)
print(anskai)