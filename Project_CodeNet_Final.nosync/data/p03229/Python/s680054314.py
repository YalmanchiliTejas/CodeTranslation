n = int(input())
a = []
for _ in range(n):
  a.append(int(input()))

def solve2(a):
  i = 1
  j = n-1
  s = 0
  x = y = a[0]
  r = True
  while i<j:
    if r:
      s += abs(a[j] - x) + abs(a[j-1] - y)
      x = a[j]
      y = a[j-1]
      j -= 2
    else:
      s += abs(a[i] - x) + abs(a[i+1] - y)
      x = a[i]
      y = a[i+1]
      i += 2
    r = not r
  if i == j:
    s += max(abs(a[i] - x), abs(a[i]-y))
  return s

print(max(solve2(sorted(a)), solve2(sorted(a, reverse=True))))
