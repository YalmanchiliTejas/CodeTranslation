import string
from collections import OrderedDict

n = int(input())

d = OrderedDict()
for i in string.ascii_lowercase:
    d[i] = d.get(i, 0) - 1

for _ in range(n):
    s = input()
    for i in string.ascii_lowercase:
        if s.count(i) == 0:
            d[i] = 0
        elif s.count(i) > 0:
            if d[i] == -1:
                d[i] = s.count(i)
            else:
                d[i] = min(d[i], s.count(i))

ans = ""

for i in d.items():
    if i[1] != 0:
        ans += i[0] * i[1]

print(ans)