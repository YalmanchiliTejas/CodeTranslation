n = int(input().rstrip())
a = list(map(int,input().rstrip().split()))
mod = 1_000_000_007
ans = 0
tmp = 0
for i in range(n-1,0,-1):
    tmp = (tmp+a[i])%mod
    ans += (tmp*a[i-1])%mod
print(ans%mod)