n = int(input())
a = list(map(int, input().split()))
ans = 0
mod = 1000000007
s = [0]*(n+1)
for i in range(n):
    s[i+1] = s[i] + a[i]
for i in range(n):
    ans += a[i]*(s[n]-s[i+1])
print(ans%mod)