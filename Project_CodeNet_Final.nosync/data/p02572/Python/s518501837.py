n=int(input())
a=[int(x) for x in input().split()]

b=[0]*n
b[0]=a[0]
for i in range(n-1):
  b[i+1]=b[i]+a[i+1]

c=0
for j in range(n-1):
  c+=a[j]*(b[n-1]-b[j])
  
print(c%(10**9+7))