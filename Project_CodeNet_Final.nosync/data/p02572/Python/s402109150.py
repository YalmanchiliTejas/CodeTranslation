mod = 10**9+7
n = int(input())
A = list(map(int,input().split()))
A.sort()
s  =sum(A)
ans = 0
for a in A:
    s-=a
    ans += a*s
    ans %= mod

print(ans%mod)