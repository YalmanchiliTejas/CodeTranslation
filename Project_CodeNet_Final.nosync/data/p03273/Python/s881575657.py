h, w = map(int, input().split())
a = []
delcol = {i: True for i in range(w)}
for _ in range(h):
    _a = input()
    if _a == "."*w:
        continue

    for _w in range(w):
        delcol[_w] &= ("." == _a[_w])

    a.append(_a)

for _a in a:
    for _w in range(w):
        if not delcol[_w]:
            print(_a[_w], end="")

    print()

