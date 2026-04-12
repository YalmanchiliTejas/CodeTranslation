n = int(raw_input())
a = raw_input().split()

b = []
c = []
for i in range(n):
  if i % 2:
    b.append(a[i])
  else:
    # b.insert(0, a[i])
    c.append(a[i])

b = c[::-1] + b

if n % 2:
  print " ".join(b)
else:
  print " ".join(b[::-1])
