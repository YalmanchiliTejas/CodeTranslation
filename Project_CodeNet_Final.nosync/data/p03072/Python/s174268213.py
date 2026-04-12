n = int(input())
h = list(map(int, input().split()))
s = 0
for i in range(n):
  t = []
  for j in range(i):
    t.append(h[j])
  if t == [] or max(t) <= h[i]:
    s = s + 1
print(s)