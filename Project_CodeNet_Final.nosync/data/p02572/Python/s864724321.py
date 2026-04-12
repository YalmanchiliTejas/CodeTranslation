n=int(input())

a=[int(i) for i in input().split()]
mod=10**9+7
goal=0
ans=0
for i in range(n):
    taishou=a.pop()
    if i != 0:
        ans+=taishou*goal
        ans=ans%mod
    goal+=taishou


print(ans)