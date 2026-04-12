from collections import defaultdict
d = defaultdict(int)
H, W = map(int, input().split())
L = []
for i in range(H):
    L.append(input())
cl = L[:]

al = []
for i in cl:
    if ('#' in i):
        al.append(i)

if (len(al) == 0):
    print()
    exit()

for i in range(W):
    d[i] = True

for i, v in enumerate(al):
    for k, j in enumerate(v):
        if (j == '.'):
            continue
        else:
            d[k] = False
for i, v in d.items():
    if (v):
        for j, k in enumerate(al):
            if (i == 0):
                al[j] = ' ' + k[1:]
            elif ((i == W - 1) and (W != 1)):
                al[j] = k[:i] + ' '
            else:
                al[j] = k[:i] + ' ' + k[i + 1:]
for i in al:
    print(i.replace(' ', ''))
