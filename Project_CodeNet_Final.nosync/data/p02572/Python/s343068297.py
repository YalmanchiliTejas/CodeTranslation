n=int(input())
a=list(map(int,input().split()))
ans=0
num=0

for i in range(n-1):
  num+=a[i]
  ans+=a[i+1]*num
  
print(ans%1000000007)