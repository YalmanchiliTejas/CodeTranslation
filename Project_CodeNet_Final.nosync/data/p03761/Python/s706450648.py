from collections import Counter
from functools import reduce
from operator import and_

n = int(input())

cs = [Counter(input()) for _ in range(n)]
enable_chars = reduce(and_, (set(c.keys()) for c in cs))

for enable_char in sorted(enable_chars):
    enable_counts = min(c[enable_char] for c in cs)
    print(enable_char * enable_counts, end="")
print()
