n = int(input())
al = list(map(int, input().split()))
mod = 10**9+7
ans = sum(al)**2

for ai in al:
    ans -= ai**2

print((ans//2)%mod)