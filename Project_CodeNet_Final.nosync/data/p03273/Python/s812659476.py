h, w = [int(x) for x in input().split()]
m = []
for i in range(h):
    m.append(input())
n = []
for i, row in enumerate(m):
    if '#' in row:
        n.append(row)
flgs = []
for j in range(w):
    js = ''.join([row[j] for row in m])
    flgs.append('#' in js)
n = [''.join([item for i, item in enumerate(s) if flgs[i]]) for s in n]
for item in n:
    print(item)