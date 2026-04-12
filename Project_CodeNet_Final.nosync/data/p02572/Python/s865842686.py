N=int(input())
l=list(map(int,input().split()))
b=10**9+7
d=(sum(l))**2
c=0
for i in range(N):
  c=c+l[i]**2
print((d-c)//2%b)