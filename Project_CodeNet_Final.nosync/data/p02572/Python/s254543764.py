n=int(input())
a=list(map(int,input().split()))
ruiseki=[0 for i in range(n)]
ruiseki[0]=a[0]
sum=0
for i in range(1,len(a)):
    ruiseki[i]=ruiseki[i-1]+a[i]
for i in range(n-1):
    sum+=a[i]*(ruiseki[n-1]-ruiseki[i])
    sum%=(10**9+7)

print(sum)

