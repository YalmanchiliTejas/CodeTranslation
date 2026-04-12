n=int(input())
a=list(map(int,input().strip().split()))[:n]
s=0;
b=[]
b.append(a[0])
for i in range(1,n):
  b.append(a[i]+b[i-1])
for i in range(0,n):
    s=s+a[i]*(b[n-1]-b[i])
    s=s%1000000007
print(s)