n=int(input())
a=list(map(int,input().split()))
ans=0
c=sum(a)
for i in range(n):
    c=c-a[i]
    b=(a[i]*c)
    ans=ans+b
d=ans%(1000000007)
print(d)
