n = int(input())
a = list(map(int,input().split()))
t = a[0]
ans = 0
mod = 10**9+7
for i in range(1,n):
    ans = (ans + t*a[i]) % mod
    t += a[i]
print(ans)