n=int(input())
aa=list(map(int,input().split()))
b=0
c=0
for a in aa:
  b+=a
  c+=a**2
x=(b**2-c)//2
print(x%(10**9+7))
