n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
k = 0
b = [0]*len(a)
ans = 0
for i in range(len(a)-1, 0, -1):
    k += a[i]
    k %= mod
    b[i] = k
for i in range(len(a)-1):
    ans += a[i] * b[i+1]
    ans %= mod

print(ans)