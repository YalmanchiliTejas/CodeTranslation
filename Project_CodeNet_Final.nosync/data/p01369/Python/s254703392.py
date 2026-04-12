import sys
import collections

left = 'qwertasdfgzxcvb'

for line in sys.stdin:
    line = line.strip()
    if line == '#':
        break
    state = 0 if line[0] in left else 1
    count = 0
    for c in line:
        next = 0 if c in left else 1
        if state != next:
            count += 1
        state = next
    print count