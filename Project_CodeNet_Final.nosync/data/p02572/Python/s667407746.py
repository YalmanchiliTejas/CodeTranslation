n=int(input())
l=list(map(int,input().split()))
a=sum(l[1:])
m=10**9+7
s=0
for v,u in zip(l[:-1],l[1:]):
    s+=v*a
    a-=u
print(s%m)
