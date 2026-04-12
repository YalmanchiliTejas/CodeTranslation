import collections
n = int(input())
s = []
for i in range(n):
    s.append(input())

c = []
for i in range(n):
    c.append(collections.Counter(s[i]))
f = []
d = []
e = []
for i in range(n):
    if i == 0:
        for j in c[i]:
            f.append(j)
            d.append([j, c[i][j]])
            e.append(c[i][j])
    else:
        for j in c[i]:
            if j in f:
                if c[i][j] < e[f.index(j)]:
                    e[f.index(j)] = c[i][j]
                    d[f.index(j)][1] = c[i][j]
p = []
for i in range(len(d)):
    for j in range(n):
        if d[i][0] not in s[j]:
            p.append(i)
            break
j = 0
for i in p:
    del d[i - j]
    j += 1
d.sort()
for i in range(len(d)):
    print(d[i][0] * d[i][1], end = '', sep='')