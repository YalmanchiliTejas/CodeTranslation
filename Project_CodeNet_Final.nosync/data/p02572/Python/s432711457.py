n = int(input())
a = list(map(int,input().split()))
ans = 0
mod = 10**9+7
s = [0]*n
s[-1] = a[-1]
for i in range(n-2,-1,-1):
    s[i] = (s[i+1]+a[i])%mod
for i in range(n-1):
    ans = (ans + (a[i]*s[i+1]))%mod
print(ans)