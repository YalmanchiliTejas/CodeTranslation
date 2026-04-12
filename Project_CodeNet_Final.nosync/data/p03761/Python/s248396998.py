from collections import Counter
from string import ascii_lowercase


n = int(input())
dic = {c: 50 for c in ascii_lowercase}
for _ in range(n):
    tmp = Counter(input())
    for c in ascii_lowercase:
        dic[c] = min(dic[c], tmp.get(c, 0))
print(''.join(c * dic[c] for c in ascii_lowercase))