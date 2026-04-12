N=int(input())
a=list(map(int, input().split()))
sum=sum(a)
b=0
c=0
for i in range(N-1):
    b+=a[i]
    c=(c+(a[i]*(sum-b))) %(10**9+7)
print(c)