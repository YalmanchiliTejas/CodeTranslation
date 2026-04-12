# solution
import math
import io
import string

data = int(input())
array = [input().rstrip() for _ in range(data)]
sets = {c: [] for c in string.ascii_lowercase}
for i in range(data):
    for c in string.ascii_lowercase:
        k = array[i].count(c)
        sets[c].append(k)
strs = ''
for c in string.ascii_lowercase:
    strs += c * min(sets[c])
print(strs)