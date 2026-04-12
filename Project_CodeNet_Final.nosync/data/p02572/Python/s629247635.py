n=int(input())
a = list(map(int,input().split()))
k=0
for i in a:
    k+=i**2
s=(sum(a)**2)
print(((s-k)//2)%(10**9+7))
