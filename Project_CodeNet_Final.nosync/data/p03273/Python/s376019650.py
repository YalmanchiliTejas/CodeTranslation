from collections import Counter
h, w = map(int, input().split(" "))
a = [input() for i in range(h)]

rr = []
for i in range(h):
    c = Counter(a[i]).most_common()
    if len(c) > 1 or c[0][0] == '#':
        rr.append(i)

rc = []
for i in range(w):
    c = Counter([x[i] for x in a]).most_common()
    if len(c) > 1 or c[0][0] == '#':
        rc.append(i)

a = '\n'.join(''.join(a[j][i] for i in rc) for j in rr)
print(a)
