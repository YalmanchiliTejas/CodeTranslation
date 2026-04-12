# Q2
H, W = map(int, input().split())
a = [[c for c in input()] for _h in range(H)]


for h in range(H):
    if '#' not in a[h]:
        for w in range(W):
            a[h][w] = ''
for w in range(W):
    if '#' not in [p[w] for p in a]:
        for h in range(H):
            a[h][w] = ''

for h in range(H):
    line = ''.join(a[h])
    if line:
        print(''.join(a[h]))