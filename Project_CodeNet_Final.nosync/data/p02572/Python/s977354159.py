n = int(input())
a = list(map(int, input().split()))
#mod_a = [i%(10**9 + 7) for i in a]
res = 0
sum_a = sum(a)
b = 0
t = 0
for i in range(0, len(a)-1):
  t = a[i]
  b += a[i]
  res += (sum_a - b)*t%(10**9 + 7)
print(res%(10**9 + 7))

