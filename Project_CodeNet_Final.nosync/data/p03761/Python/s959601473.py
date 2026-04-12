n = int(input())
d = dict()
for i in range(n):
    dd = dict()
    s = input().strip()
    for c in set(s):
        dd[c] = s.count(c)

    if i == 0:
        d = dd
    else:
        deleted = []
        for c, count in d.items():
            if c not in dd:
                deleted.append(c)
                continue

            d[c] = min(d[c], dd[c])

        for c in deleted:
            del d[c]

s = ''
for c, count in sorted(d.items(), key=lambda x: x[0]):
    s += c * count

if s != '':
    print(s)