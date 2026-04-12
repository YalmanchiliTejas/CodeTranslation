from string import*
from collections import*
_, *s = map(Counter, open(0))
a = ""
for i in ascii_lowercase:
    a += i * min(c.get(i, 0) for c in s)
print(a)