H, W = map(int, input().split())
a1 = []
for y in range(H):
    c = list(input())
    if '#' in c:
        a1.append(c)
a2 = list(zip(*a1))
a3 = []
for x in range(W):
    r = a2[x]
    if '#' in r:
        a3.append(r)
a4 = list(zip(*a3))
for r in a4:
    print(''.join(r))
