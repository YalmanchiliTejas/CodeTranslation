n=int(input())
z=[int(x) for x in input().split(' ')]
s=sum(z)
md=1000000007
ans=0
for i in range(n):
    s-=z[i]
    ans+=s*z[i]
print(ans%md)