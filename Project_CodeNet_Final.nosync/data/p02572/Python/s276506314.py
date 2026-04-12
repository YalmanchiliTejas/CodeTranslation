n= int(input().strip())
a= list(map(int, input().strip().split()))
x=0
A=0

for i in range(n):
    A+=a[i]
x=0
for i in range(n):
    x+=a[i]*(A-a[i])
x=x//2
x=x%(10**9+7)
print(x)