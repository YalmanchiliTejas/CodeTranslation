n,*a=map(int,open(0).read().split())

b=sum(map(lambda x:x*x,a))
mod=10**9+7
ans=(sum(a)**2-b)//2

print(ans%mod)
