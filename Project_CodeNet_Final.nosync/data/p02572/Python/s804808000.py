t = int(input())
s = [int(i) for i in input().split()]
c = 0
n = s[0]
for i in range(1, t):
  c += n * s[i]
  n += s[i]
mod = 10**9 + 7
print(c%mod)