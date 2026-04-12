from collections import Counter
from collections import defaultdict

n = int(input())
d = defaultdict(int)
S = input()
for k in S:
    d[k] += 1
for _ in range(n-1):
    count = Counter(input())
    for k in d.keys():
        if not k in count:
            d[k] = 0
        else:
            d[k] = min(d[k], count[k])
ans = ''
for i in 'abcdefghijklmnopqrstuvwxyz':
    ans += i * d[i]
print(ans)