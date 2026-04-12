
n = int(input())
mod = 1000000007
a = list(map(int,input().split()))
width = 0
ans = 0
for i in range(n):
    ans = (ans + a[i]*width)  % mod
    width = (width + a[i]) % mod

print(ans)