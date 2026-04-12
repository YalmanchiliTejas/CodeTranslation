import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**6)

n=int(input().rstrip())
a=[int(i) for i in input().split()]

mod=10**9+7

csum=[0]
for i in a:
    csum.append((csum[-1]+i)%mod)

ans=0
c=n-1
for i in range(n-1):
    ans+=a[i]*(csum[-1]-csum[i+1])
    ans%=mod

print(ans)