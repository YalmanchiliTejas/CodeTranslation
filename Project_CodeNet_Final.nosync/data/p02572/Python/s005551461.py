n=int(input())
*a,=map(int,input().split())
s=sum(a)%(10**9+7)
c=0
b=0
for i in range(n):
    b+=a[i]
    amod=a[i]%(10**9+7)
    c+=(s-b)*amod
print(c%(10**9+7))