n=int(input())
a=list(map(int,input().split()))
k=0
b=[a[0]]
for i in range(n-1):
    b+=[b[-1]+a[i+1]]
    k+=a[i+1]*b[-2]
print(k%(10**9+7))