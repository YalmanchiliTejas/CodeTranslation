n = int(input())
S = [input() for _ in range(n)]

from collections import Counter

counters = [Counter(s) for s in S]

all = set(counters[0])
for counter in counters:
    all &= set(counter)

minc = {c:100 for c in all}
for c in all:
    for counter in counters:
        minc[c] = min(minc[c], counter[c])

print("".join(c * minc[c] for c in sorted(minc.keys())))
