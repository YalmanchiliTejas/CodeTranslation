n = int(input())
h = list(map(int, input().split()))
c = 0
for i in range(n):
  if i != 0 and h[i] < max(h[:i]):
    continue
  c += 1
print(c)