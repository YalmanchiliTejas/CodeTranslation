n=int(input())
a=list(map(int,input().split()))
x=sum(a)**2
y=sum(a[i]**2 for i in range(n))
print(((x-y)//2)%1000000007)

