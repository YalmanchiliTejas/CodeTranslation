n = int(input())
a = list(map(int,input().split()))
ans = 0
mod = 10**9+7
sa = [0]
for i in range(n):
    sa.append((sa[i]+a[i])%mod)
for i in range(n-1):
    ans += a[i]*(sa[-1]-sa[i+1])
print(ans%mod)