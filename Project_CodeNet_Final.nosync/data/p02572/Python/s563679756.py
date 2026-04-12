n=int(input())
*a,=map(int,input().split())
b=[x**2 for x in a]

mod=10**9+7
print(((sum(a)**2-sum(b))//2)%mod)