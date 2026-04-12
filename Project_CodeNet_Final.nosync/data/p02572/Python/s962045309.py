n=int(input())
a=list(map(int,input().split()))
d=[0]*n
for i in range(n):
  d[i]=a[i]**2
print(((sum(a)**2-sum(d))//2)%(10**9+7))