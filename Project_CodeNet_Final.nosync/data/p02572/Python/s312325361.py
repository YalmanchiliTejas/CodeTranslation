n=int(input())
a=list(map(int,input().split()))
b=[a[0]]
k=0
for i in range(1,n):
    b.append(a[i]+b[i-1])
for i in range(n-1):
    k+=a[i]*(b[n-1]-b[i])
print(k%(10**9+7))
