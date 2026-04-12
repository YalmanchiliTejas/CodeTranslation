n = int(input())
seq = list(map(int, input().split()))
a = 10 ** 9 + 7
s = sum(seq)
res = 0
for i in range(n - 1):
  s -= seq[i]
  res += (seq[i] * s) % a
print(res % a)