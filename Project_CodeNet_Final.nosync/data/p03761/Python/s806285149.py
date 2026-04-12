N = int(input())
SS = []
for _ in range(N):
    SS.append(sorted(input()))
common = SS[0]
for s in SS:
    sc = s[:]
    z = []
    for c in common:
        if c in sc:
            sc.remove(c)
            z.append(c)
    common = z
print(''.join(common))