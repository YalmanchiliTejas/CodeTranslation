H, W = map(int, input().split())
a = [input() for i in range(H)]
b = []
for i in range(H):
    if '#' in a[i]:
        b.append(a[i])
c = [i for i in zip(*b)]

d =[]
for i in range(len(c)):
    if '#' in c[i]:
        d.append(c[i])
e = [i for i in zip(*d)]

for i in e:
    print(''.join(i))