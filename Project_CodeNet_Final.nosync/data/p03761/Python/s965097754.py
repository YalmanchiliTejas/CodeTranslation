n = int(input())
from collections import Counter

c = Counter(input())
for i in range(1, n):
    tmp = Counter(input())
    c = c & tmp
print("".join(sorted(c.elements())))