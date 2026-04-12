n=int(input())
l=list(map(int,input().split()))
suml=sum(l)
num=0
for i in range(n-1):
    suml-=l[i]
    num+=(l[i]*suml)%(10**9+7)
print(num%(10**9+7))