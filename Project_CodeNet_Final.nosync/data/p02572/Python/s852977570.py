n = int(input())
a = list(map(int,input().split()))
mod = 10**9 + 7
invtwo = pow(2, mod-2, mod)
s = sum(a) % mod
ans = 0
for x in a:
  ans += (s-x) * x
  ans %= mod
print((ans * invtwo) % mod)