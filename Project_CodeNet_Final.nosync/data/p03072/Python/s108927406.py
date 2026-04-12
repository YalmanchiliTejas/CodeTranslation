N, *H = map(int, open(0).read().split())
c = 1
for i, h in enumerate(H):
    b = []
    for j in range(i):
        if H[j] <= h:
            b.append(True)
        else:
            b.append(False)
    
    if not len(b) == 0 and all(b):
        c += 1

print(c)