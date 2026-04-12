mod = 10**9+7

n = int(input())
a = list(map(int,input().split()))

s = sum(a)%mod
ans = 0

for i in a:
    s -=i
    s %= mod
    ans += s*i
    ans %=mod
ans %=mod
print(ans)