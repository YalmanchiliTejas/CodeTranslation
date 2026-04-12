n=int(input())
l=[int(i) for i in input().split()]
ans=0
mod=1000000007
sql=(sum(l))**2
for i in l:
    ans+=i*i
print((sql-ans)//2%mod)
