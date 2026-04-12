h, w = map(int, input().split())
a = [ list(input()) for _ in range(h) ]

rows = [ False for _ in range(h) ]
cols = [ False for _ in range(w) ]

# 必要な行idを列挙
for y in range(h):
    is_ok = False
    for x in range(w):
        if a[y][x] != ".":
            is_ok = True
    if is_ok:
        rows[y] = True

# 必要な列idを列挙
for x in range(w):
    is_ok = False
    for y in range(h):
        if a[y][x] != ".":
            is_ok = True
    if is_ok:
        cols[x] = True

for y in range(h):
    if not rows[y]:
        continue
    for x in range(w):
        if rows[y] and cols[x]:
            print(a[y][x], end = "")
    print()
