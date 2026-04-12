mod=10**9+7

n=int(input())
a=list(map(int,input().split()))
a=[0]+a
ruiseki=[0]*(n+1)

for i in range(n+1):
  ruiseki[i]=(ruiseki[i-1]+a[i])

ans=0
for i in range(1,n+1):

  ans+=(a[i]*(ruiseki[n]-ruiseki[i]))
print(ans%mod)

  
