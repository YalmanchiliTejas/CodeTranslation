from collections import Counter
from string import ascii_lowercase


n = int(input())
INF = 1 << 31
dic = {c: INF for c in ascii_lowercase}
for _ in range(n):
    tmp = Counter(input())
    for c in ascii_lowercase:
        dic[c] = min(dic[c], tmp.get(c, 0))

ans = ''
print(''.join(c * dic[c] for c in ascii_lowercase))