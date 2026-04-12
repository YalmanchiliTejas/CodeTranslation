n=int(input())
a=list(map(int,input().strip().split()))[:n]
b=[]
b.append(a[0])
sum = 0
for i in range(1,n):
  b.append(a[i]+b[i-1])
for i in range(0,n-1):
    sum=sum+a[i]*(b[n-1]-b[i])
    sum=sum%1000000007
print(sum)