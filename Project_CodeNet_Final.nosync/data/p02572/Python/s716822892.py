n=int(input())
a=list(map(int, input().split()))
s=0
t=0
for i in range (n):
    s+=a[i]
    t+=a[i]*a[i]
u=(s*s-t)//2
print(u%1000000007)
