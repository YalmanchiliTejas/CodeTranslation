n = int(input())
h = list(map(int, input().split()))

c = 0

for i in range(n):
  t = True
  for j in range(i):
    if h[j] > h[i]:
      t = False
      break
  if t == True:
    c += 1
  t = True
print(c)