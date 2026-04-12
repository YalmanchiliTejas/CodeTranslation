n = int(input())
l = list(map(int,input().split()))
mod=10**9+7
tot=sum(l)

ans=0
for i in range(n):
    ans+=l[i]*(tot-l[i])

print((ans//2)%mod)
