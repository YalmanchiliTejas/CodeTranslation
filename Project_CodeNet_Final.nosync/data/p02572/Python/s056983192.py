n=int(input())
a=list(map(int,input().split()))
b=[0]
s=0
for i in range(n):
    b+=[b[-1]+a[i]]
    s+=b[-2]*a[i]
print(s%(10**9+7))