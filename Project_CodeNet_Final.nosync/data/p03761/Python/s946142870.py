from collections import Counter

n = int(input())
cnt = dict(zip(map(chr, range(97, 123)), [50] * 26))

for _ in range(n):
    c = Counter(input())
    for k in cnt.copy().keys():
        if c[k] == 0:
            del cnt[k]
        else:
            cnt[k] = min(cnt[k], c[k])

if len(cnt) == 0:
    print()
else:
    res = ''
    for k, v in sorted(cnt.items()):
        res += k * v
    print(res)
