n=int(input())
a=[int(x) for x in input().split()]
m=10**9+7
s=0
for c in range(n):
    s=(s+a[c])%m
s=pow(s,2,m)
for c in range(n):
    s=(s-pow(a[c],2,m))%m
if s%2==0:
    print(s//2)
else:
    print((s+m)//2)