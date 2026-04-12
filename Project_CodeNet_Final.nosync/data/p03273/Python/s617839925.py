H,W = map(int,input().split())
a = []
for h in range(H):
    row = list(input())
    if '#' in row:
        a.append(row)
H = len(a)
for w in range(W):
    T = 1
    for h in range(H):
        if a[h][w] == '#':
            T = 0
            break
    if T == 1:
        for h in range(H):
            a[h][w] = 0
for h in range(H):
    a[h] = [w for w in a[h] if w != 0]
for h in range(H):
    print(''.join(a[h]))
