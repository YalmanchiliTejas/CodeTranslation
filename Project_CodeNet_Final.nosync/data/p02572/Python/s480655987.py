n=int(input())
a=list(map(int,input().split()))
b=sum(a)
c=0
for v in range(n-1):
  b-=a[v]
  c+=a[v]*b
print(c%(10**9+7))  
