from string import ascii_lowercase as l
from collections import Counter
_, *s = map(Counter, open(0))
t = ""
for a in l:
  t += a * min(c.get(a, 0) for c in s)
print(t)