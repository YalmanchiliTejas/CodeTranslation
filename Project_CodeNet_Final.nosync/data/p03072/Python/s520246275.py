n = int(input())
h = list(map(int, input().split()))
c = 0
for i in range(n):
  l = h[:i+1]
  if max(l) == h[i]:
    c += 1
print(c)