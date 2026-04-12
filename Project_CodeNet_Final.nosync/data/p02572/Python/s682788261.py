n=int(input())
a=list(map(int,input().split()))
if sum(a)==0:
    print(0)
    exit()
else:
    k=0
    s=sum(a)
    for i in range(n-1):
        s-=a[i]
        s1=s%(10**9+7)
        k+=(s1*a[i])%(10**9+7)
print(k%(10**9+7))