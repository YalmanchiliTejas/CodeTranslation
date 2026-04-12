n = int(input())
a = list(map(int,input().split()))
mod = 10**9 + 7

s = [0]*n
for i in reversed(range(1,n)):
    s[i-1] = s[i] + a[i]
# print(s)

ans = 0
for i in range(n-1):
    ans += a[i]*s[i] % mod

print(ans % mod)