n = int(input())
ls = list(map(int,input().split()))
di = [0]*(n+1)
mod = 10**9+7
ans = 0
for i in range(1,n+1):
    di[i] = di[i-1] + ls[i-1]
for j in range(n-1):
    ans += ls[j]*(di[n]-di[j+1]) % mod
print(ans%mod)