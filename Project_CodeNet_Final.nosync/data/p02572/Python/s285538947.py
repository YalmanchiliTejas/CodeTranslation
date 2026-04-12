n=int(input())
l=[int(j)for j in input().split()]
mod=10**9+7
ll=[i**2 for i in l]
ans=(sum(l)**2-sum(ll))//2
print(ans%mod)