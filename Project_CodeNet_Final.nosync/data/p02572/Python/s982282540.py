N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7
a = sum(A) ** 2 % mod
b = sum([a * a for a in A]) % mod
p = mod - 2
bin_p = []
while p:
  bin_p.append(p % 2)
  p >>= 1
ret = 1
for j in reversed(bin_p):
  ret = (ret * ret) % mod
  if j == 1:
    ret = (ret * 2) % mod
print((a - b) * ret % mod)