n=int(input())
a=list(map(int,input().split()))

modx=10**9+7
suma=sum(a)
sumx=0
for i in range(n-1):
  suma-=a[i]
  sumx=(sumx+ a[i]*suma)%modx
    
print(sumx)