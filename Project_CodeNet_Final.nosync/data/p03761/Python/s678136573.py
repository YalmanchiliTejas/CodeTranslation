from collections import Counter

N = int(input())
strings = [input() for _ in range(N)]
ctypes = set(''.join(strings))
counters = [Counter(s) for s in strings]

s = ''

for c in ctypes:
    s += c * min([counter[c] for counter in counters])

print(''.join(sorted(s)))
