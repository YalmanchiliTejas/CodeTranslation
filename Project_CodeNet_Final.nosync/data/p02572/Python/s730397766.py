n=int(input())
inf=10**9+7
a=list(map(int,input().split()))
sum=0
for i in range(n):
    sum+=a[i]
norm=0
for i in range(n):
    norm+=a[i]**2
x=(sum**2-norm)//2
print(x%inf)