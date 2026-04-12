h, w = map(int, input().split())
a = []

for i in range(h):
    a.append(input())

b = []

for i in range(h):
    if any(c == '#' for c in a[i]):
        b.append(a[i])

#print(b)

c = []
for i in range(w):
    s = ''
    for j in range(len(b)):
        s += b[j][i]
    c.append(s)

#print(c)
d = []

for i in range(len(c)):
    if any(c == '#' for c in c[i]):
        d.append(c[i])

#print(d)

e = []
for i in range(len(d[0])):
    s = ''
    for j in range(len(d)):
        s += d[j][i]
    e.append(s)

for i in range(len(e)):
    print(e[i])
