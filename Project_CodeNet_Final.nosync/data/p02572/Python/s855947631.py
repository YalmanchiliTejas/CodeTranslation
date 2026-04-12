N = int(input())
a = [int(x) for x in input().split()]
a.sort(reverse=True)
rui = [0]*N
rui[0] = a[0]
mod = 10**9+7
for i in range(1,N):
    rui[i] = rui[i-1] + a[i]
ans = 0
for i in range(1,N):
    ans = (ans + a[i] * rui[i-1])%mod
print(ans)