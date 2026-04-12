n, x, m = map(int, input().split())
a = x
s = 0
h = []
h.append(a)
i = 0
fl = 0
while i < n:
    s += a
    a = (a*a) % m
    if a == 0:
      break
    i += 1
    if fl == 0 and a in h:
      fl = 1
      po = h.index(a)
      ss = 0
      for j in range(po):
        ss += h[j]
      s2 = s - ss
      f = (n - po) // (i - po)
      s2 *= f
      s = s2 + ss
      i2 = i - po
      i2 *= f
      i = i2 + po
    else:
      h.append(a)
print(s)