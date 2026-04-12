n = int(input())
al = list(map(int, input().split()))

ans = sum(al)**2
for a in al:
    ans -= a**2

mod = 10**9+7
print((ans//2)%mod)