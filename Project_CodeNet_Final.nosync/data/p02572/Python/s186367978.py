n=int(input())
a=list(map(int,input().split()))

sm=0
sumj=sum(a)

for i in range(n-1):
  sumj-=a[i]
  sm+=sumj*a[i]


print(sm%((10**9)+7))
