n=int(input())
a=[int(x) for x in input().split()]
b=[0]
for i in range(n):
  b.append(b[i]+a[i])
c=0
for j in range(n-1):
  c+=a[j]*(b[n]-b[j+1])
  while c//(10**9+7)>0:
    c%=10**9+7
print(c)