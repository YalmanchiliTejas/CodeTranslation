n=int(input())
a=list(map(int,input().split()))
x=sum(a)
y=0
for i in range(n):
    y+=a[i]**2

ans = (x**2 - y)//2

ans = ans % (10**9+7)

print(int(ans))
