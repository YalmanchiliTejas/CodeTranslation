n = int(input())
a = list(map(int, input().split()))
s = sum(a)
ans = 0
# for i in range(1,n):
#     ans = 
t = s
mod = 10**9+7
for i in range(n-1):
    t -= a[i]
    ans += a[i]*t
    ans %= mod

print(ans)

