n = int(input())
a = list(map(int,input().split()))
s = []
a.reverse()
s.append(a[0])
for i in range(n-1):
    s.append(s[-1]+a[i+1])
mod = 10**9+7
ans = 0
a.reverse()
for i in range(n-1):
    ans += a[i]*s[-2-i]
    ans = ans % mod
print(ans)