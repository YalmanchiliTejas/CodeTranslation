H, W = map(int, input().split())
A = [input() for i in range(H)]
B = []
for a in A:
    if not all([x == '.' for x in a]):
        B.append(a)
C = zip(*[b for b in zip(*B) if '#' in b])
for c in C:
    print(*c, sep='')
