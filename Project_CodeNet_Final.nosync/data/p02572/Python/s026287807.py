from sys import stdin
inp = lambda : stdin.readline().strip()

n = int(inp())
mod = 10**9 + 7
a =[int(x) for x in inp().split()]
s = [a[0]]
for i in range(1,n):
    s.append(s[i-1]+a[i])
ans = 0
for i in range(n):
    ans +=  ((a[i]%mod) * (s[-1] - s[i])%mod)%mod
    ans %= mod
print(ans)