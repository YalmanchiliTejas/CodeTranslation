h, w = map(int, input().split())
a = [input() for _ in range(h)]
blank_h, blank_w = set(), set()
for i in range(h):
    count = 0
    for j in range(w):
        if a[i][j] != '.':
            break
        count += 1
    if count == w:
        blank_h.add(i)
for j in range(w):
    count = 0
    for i in range(h):
        if a[i][j] != '.':
            break
        count += 1
    if count == h:
        blank_w.add(j)
for i in range(h):
    if i in blank_h:
        continue
    for j in range(w):
        if j in blank_w:
            continue
        print(a[i][j], end='')
    print()