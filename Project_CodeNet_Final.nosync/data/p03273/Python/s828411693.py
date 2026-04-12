h, w = map(int, input().split())
a = [input() for _ in range(h)]

b = []
for y in range(len(a)):
    for x in range(len(a[y])):
        if a[y][x] != '.':
            b.append(a[y])
            break

c = ['' for _ in range(len(b))]
for x in range(len(b[0])):
    for y in range(len(b)):
        if b[y][x] != '.':
            for y in range(len(b)):
                c[y] += b[y][x]
            break

print('\n'.join(c))